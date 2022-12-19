using System;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Text;
using System.Threading;


//멀티쓰레드는 크래시를 계속 내면서 연습하는거다
namespace ServerCore
{
    class Session
    {
        Socket _socket;
        int _disconnected = 0;

        object _lock = new object();

        Queue<byte[]> _sendQueue = new Queue<byte[]>();
        bool _pending = false; //한번이라도 레지스터 샌드시 true -> OnSendingComplete시 false로

        List<ArraySegment<byte>> _pendingList = new List<ArraySegment<byte>>(); //BufferList에 한번에 때려박기 위해 만든 리스트
        SocketAsyncEventArgs _sendArgs = new SocketAsyncEventArgs();
        SocketAsyncEventArgs _recvArgs = new SocketAsyncEventArgs();
        //전역변수에 버퍼 객체를 놓는게 C++스타일이다.

        public void Start(Socket socket)
        {
            _socket = socket;
            //SocketAsyncEventArgs recvArgs = new SocketAsyncEventArgs();
            _recvArgs.Completed += new EventHandler<SocketAsyncEventArgs>(OnRecvCompleted);
            //수신을 위한 버퍼를 준비한다. 인자 -> 버퍼 선언, 시작점, 버퍼의 크기
            _recvArgs.SetBuffer(new byte[1024], 0, 1024);
            _sendArgs.Completed += new EventHandler<SocketAsyncEventArgs>(OnSendCompleted);
            RegisterRecv(_recvArgs);
        }

        //Send는 예고가 없기 때문에 예외처리가 많다.
        public void Send(byte[] sendBuff)
        {
            /*
            _sendQueue.Enqueue(sendBuff);
            if (_pending == false)
                RegisterSend();
            */
            //이상 싱글스레드시에 pending시

            lock (_lock)
            {
                _sendQueue.Enqueue(sendBuff); //버퍼를 임시 저장 후
                if (_pendingList.Count == 0)//팬딩 여부를 확인, 단일 객체가 아니라 List로도 바로 가능하다.
                    RegisterSend();
            }

            // 아래 내용은 재사용이 불가능하다.
            //_socket.Send(sendBuff);
            //SocketAsyncEventArgs sendArgs = new SocketAsyncEventArgs();
            _sendArgs.Completed += new EventHandler<SocketAsyncEventArgs>(OnSendCompleted);
            //출력할 버퍼는 파라미터로부터 받아온다.
            //MMO에서 동접자가 많아질때 이 부분을 항상 실행하면 반드시 서버 부하가 너무 커진다.
            //RegisterSend(_sendArgs);
            RegisterSend();
            //sendArgs.SetBuffer(new byte[1024], 0, 1024);
            
            //별도의 이벤트를 사용하지 않고 하나의 이벤트를 재사용하기 때문에 반드시 문제가 생길 수 있다 -> 큐에 버퍼를 넣고 한번에 하나씩만 전송할 예정
            //완료되기 전에는 큐에 내용을 보내지 않는다.(비동기처리의 특성)
            //여러 행동의 세트를 한번에 묶어서 한번에 보내는 방식이 성능 개선을 노리기에 유리하다. 단 이것을 클라에서 할 겉가 서버에서 해줄건가는 모를 일. 주로 서버에서 하는게 맞다고 본다.
        }

        public void Disconnect()
        {
            if (Interlocked.Exchange(ref _disconnected, 1) == 1)
                return;

            _socket.Shutdown(SocketShutdown.Both);
            _socket.Close();
        }

        #region Network Communication

        //register를 위한 변수가 클래스 멤버변수로 선언되어 있으니 굳이 파라미터로 전달할 필요는 없어서 이벤트 파라미터를 제거
        // 상위 실행 함수에서 이미 락을 걸었으므로 여기서는 크게 걸 필요 없음
        //한번에 보낼 수 있는 양을 체크해서 처리해야한다.
        void RegisterSend()
        {
            _pending = true;
            //다른 스레드가 들어왔을 시 pending 상태를 다시 체크해줘야함
            //byte[] buff = _sendQueue.Dequeue();
            //_sendArgs.SetBuffer(buff, 0, buff.Length);

            while (_sendQueue.Count > 0)
            {
                byte[] buff = _sendQueue.Dequeue();
                //arrSegment로 넣어야지 안그러면 작동하지 않는다, 배열의 일부를 나타내는 구조체 -> heap이 아니라 stack에 기록되는 함수이다.
                //_sendArgs.BufferList.Add(new ArraySegment<byte>(buff, 0, buff.Length)); //좌측 코드처럼 Add로 하나씩 넣으면 안된다. 다 만들고 list를 한번에 때려박아야한다. MSDN에도 나와있는 권장사항
                //buff는 1번 인덱스의 주소를 넘겨준거다.
                _pendingList.Add(new ArraySegment<byte>(buff, 0, buff.Length));
                //여기서 하나씩 segment를 채워주고
            }

            _sendArgs.BufferList = _pendingList;
            //송신버퍼에 여기서 한번에 넣어줘야 오류가 생기지 않는다.
            //송신버퍼 리스트에 모아보내기는 실무에서 이거보다 더 많은 작업이 필요하다.

            //멀티스레드 환경에 대비된 함수인 SendAsync, 커널단에서 사용하는 함수이므로 남발하면 굉장히 느려진다.
            bool pending = _socket.SendAsync(_sendArgs);
            if (pending == false)
                OnSendCompleted(null, _sendArgs);
        }

        //Register send에서 호출되면 락이 필요없지만, 콜백 방식으로 호출시를 대비해 락을 여기서도 걸어야한다.
        void OnSendCompleted(object socket, SocketAsyncEventArgs args)
        {
            lock (_lock)
            {
                if (args.BytesTransferred > 0 && args.SocketError == SocketError.Success)
                {
                    try
                    {
                        /*
                        if (_sendQueue.Count > 0)
                            RegisterSend();
                        _pending = false;
                        //sendQueue를 확인 후 count가 0이 아니라면 register send를 다시호출
                        */

                        _sendArgs.BufferList = null;
                        _pendingList.Clear();
                        //전송이 완료되었으니 버퍼랑, 대기상태 모두 초기화 onsendcompleted 함수가 호출 된 순간 이미 모두 완료가 되었다는 소리임
                        Console.WriteLine($"Transfered Bytes: {_sendArgs.BytesTransferred}");
                        //몇 바이트를 전송했는지 알아보는 로그
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine(e.ToString());
                    }
                }
                else
                {
                    Disconnect();
                }
            }
        }

        void RegisterRecv(SocketAsyncEventArgs args)
        {
            bool pending = _socket.ReceiveAsync(args);
            if (pending == false)
                OnRecvCompleted(null, args);
        }

        //파라미터를 아래와 같이 설정하지 않으면 Init의 EventHandler 선언 형식과 맞지 않아진다.
        void OnRecvCompleted(object sender, SocketAsyncEventArgs args)
        {
            //여기가 Listener과 크게 달라진다
            if (args.BytesTransferred > 0 && args.SocketError == SocketError.Success)
            {
                try
                {
                    //Todo
                    //인자 : 수신 대상 버퍼, 시작점, 몇 바이트를 받았는가?
                    string recvData = Encoding.UTF8.GetString(args.Buffer, args.Offset, args.BytesTransferred);
                    Console.WriteLine($"[From Client] {recvData}");
                }
                catch(Exception e)
                {
                    Console.WriteLine($"OnRecvFailed {e}");
                }
            }
            else
            {
                //Todo Disconnect;
                Disconnect();
            }
        }
    }
    #endregion
}
