using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.Net;

namespace ServerCore
{
    class Listener
    {
        Socket _listenSocket;
        //Action<Socket> _onAcceptHandler;
        Func<Session> _sessionFactory;   //return타입은 Session이 된다

        public void Init(IPEndPoint endPoint, Func<Session> sessionFactory)
        {
            //리스너 소켓을 초기화한다.
            _listenSocket = new Socket(endPoint.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            _sessionFactory += sessionFactory; 
            //앤드포인트를 바인딩
            _listenSocket.Bind(endPoint);
            //최대 대기자 수를 10으로 설정한다.
            _listenSocket.Listen(10);

            //사용자가 너무 몰려서 문제가 될 경우, 비동기 처리를 여러번 시작할 수 있게 만들기
            for (int i = 0; i < 10; i++)
            {
                //초기화 시점에서 처리부분을 수행(처리내용 : 등록)
                SocketAsyncEventArgs args = new SocketAsyncEventArgs();
                //문제는 반복 실행시 여기서 Race Condition이 발생할 수 있다. -> Red Zone에 들어간다.
                args.Completed += new EventHandler<SocketAsyncEventArgs>(OnAcceptCompleted);
                //처음에 한번만 등록을 바로 해준다. 비동기 처리를 위한 리스너 소켓을 준비하는 느낌
                RegisterAccept(args);
            }
        }

        //처리를 예약만 한다. 근데 pending이 없으면 바로 실행
        void RegisterAccept(SocketAsyncEventArgs args)
        {
            //한번 비동기 처리가 완료된 뒤에는 ClientSocket을 지워주지 않으면 에러가 반드시 발생한다. 쓰레기 값이 들어가 있는 것과 같으므로 초기화 해야한다.
            args.AcceptSocket = null;
            
            //C#만의 독특한 처리방식 C++는 pending 변수를 따로 선언하지 않는다.
            bool pending = _listenSocket.AcceptAsync(args);

            if (pending == false)   //pending 없이 바로 실행된 경우
                OnAcceptCompleted(null, args);
            //여기가 Accept가 성공했는지 챙기는 부분
        }

        //실제 클라이언트가 Connect 처리요청이 왔을 때 호출되는 함수, 어떻게든 접속 시도시 한번은 여길 거치게 된다.
        //SocketAsyncEventArgs를 이용해 처리에 필요한 정보를 전달한다.
        void OnAcceptCompleted(object sender, SocketAsyncEventArgs args)
        {
            if (args.SocketError == SocketError.Success) //소켓 에러 여부를 확인
            {
                Session session = _sessionFactory.Invoke();
                session.Start(args.AcceptSocket);   //gameSession은 
                session.OnConnected(args.AcceptSocket.RemoteEndPoint);
                //TODO, 에러가 없으면 처리할 내용, 여기선 실제로 클라이언트가 접속했을 때, callback 방식을 이용한다.
                //_onAcceptHandler.Invoke(args.AcceptSocket);
            }
            else
                Console.WriteLine(args.SocketError.ToString());

            //뭐가되었던 처리가 완료되었으니 다시 비동기 처리 대기를 실시
            RegisterAccept(args);
        }
    }
}
