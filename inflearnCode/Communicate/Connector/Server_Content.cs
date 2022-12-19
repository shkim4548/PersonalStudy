using System;
using static System.Collections.Specialized.BitVector32;
using System.Net;
using System.Text;
using System.Threading;
using System.Net.Sockets;
using ServerCore;

namespace Server
{
    class GameSession : Session //여기가 컨텐츠 단
    {
        public override void OnConnected(EndPoint endPoint)
        {
            byte[] sendBuff = Encoding.UTF8.GetBytes("Welcome to MMORPG server");
            Send(sendBuff);

            Thread.Sleep(100);

            Console.WriteLine($"OnConnected : {endPoint}");
            Disconnect();
        }

        public override void OnDisconnected(EndPoint endPoint)
        {
            Console.WriteLine($"OnDisconnected : {endPoint}");
        }

        public override void OnRecv(ArraySegment<byte> buffer)
        {
            //원래 하드코딩된 내용을 이벤트 콜백 아래에 넣어버림
            string recvData = Encoding.UTF8.GetString(buffer.Array, buffer.Offset, buffer.Count);
            //여기서 메시지를 받았고 처리하는 내용을 추가할 예정
            Console.WriteLine($"[From Client] {recvData}");
        }

        public override void OnSend(int numOfBytes)
        {
            Console.WriteLine($"Transfered Bytes: {numOfBytes}");
        }

    }

    class Program
    {
        static Listener _listener = new Listener();
        /*
        static void OnAcceptHandler(Socket clientSocket)
        {
            try
            {
                /*
                //수신, Session으로 넘겨짐
                byte[] recvBuff = new byte[1024];
                int recvBytes = clientSocket.Receive(recvBuff);
                //수신시 몇 바이트인지 무결성을 검사하기 위해 사용, 문자열을 받을거라는 전제하에 만든 내용 나머지는 받지 못한다.
                string recvData = Encoding.UTF8.GetString(recvBuff, 0, recvBytes);
                Console.WriteLine($"[From Client] : {recvData}");
                
                //전송, 수신과 반대순서로 간다. Session으로 넘겨짐
                byte[] sendBuff = Encoding.UTF8.GetBytes("Welcome to MMORPG Server");
                clientSocket.Send(sendBuff);

                //연결 종료
                //연결 종료 전에 미리 예고한다.
                clientSocket.Shutdown(SocketShutdown.Both);
                //완전히 종료한다.
                clientSocket.Close();
                

                //송수신 세션을 새로 구성
                //여기서 세션
                GameSession session = new GameSession();
                session.Start(clientSocket);    //이 내용의 성격은 엔진에서 처리하는게 더 자연스럽다

                byte[] sendBuff = Encoding.UTF8.GetBytes("Welcome to MMORPG server");
                session.Send(sendBuff);

                Thread.Sleep(100);
            }
            catch(Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
        */

        static void Main(string[] args)
        {
            //DNS(Domain Name System) : 서버 도메인 주소를 IP
            // IP로 서버 주소를 줬을 때 유동 IP의 경우 자동으로 변경된 IP가 적용되지 않는다. -> 도메인 네임을 등록 후 그에 맞는 IP를 바인딩해준다
            string host = Dns.GetHostName();
            IPHostEntry ipHost = Dns.GetHostEntry(host);
            IPAddress ipAddr = ipHost.AddressList[0];
            IPEndPoint endPoint = new IPEndPoint(ipAddr, 7777);//(IP주소, port 번호)

            //만들게될 세션을 여기서 정의해야한다.
            //_listener.Init(endPoint, OnAcceptHandler);
            _listener.Init(endPoint, () => { return new GameSession(); });

            while (true)
            {
                //프로그램 실행 상태를 유지하기 위해 남겨둔다.
                ;
            }
        }
    }
}
