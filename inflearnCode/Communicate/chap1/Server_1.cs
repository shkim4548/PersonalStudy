using System;
using System.Threading;
using System.Threading.Tasks;
using System.Text;
using System.Text.Encodings;
using System.Net.Sockets;
using System.Net;

namespace ServerCore
{
    class Program
    {

        static void Main(string[] args)
        {
            //DNS(Domain Name System) : 서버 도메인 주소를 IP
            // IP로 서버 주소를 줬을 때 유동 IP의 경우 자동으로 변경된 IP가 적용되지 않는다. -> 도메인 네임을 등록 후 그에 맞는 IP를 바인딩해준다
            string host = Dns.GetHostName();
            IPHostEntry ipHost = Dns.GetHostEntry(host);
            IPAddress ipAddr = ipHost.AddressList[0];
            IPEndPoint endPoint = new IPEndPoint(ipAddr, 7777);//(IP주소, port 번호)

            //소켓 초기화 및 생성
            Socket listenSocket = new Socket(endPoint.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            try//예외에 대응하기 위해 try catch를 사용한다.
            {
                //위에서 초기화된 내용에 맞게 Bind 실시
                listenSocket.Bind(endPoint);
                //backlog : 대기자 최대 허용 수, 이걸 넘어가면 대기조차 허용하지 않는다.
                //수신 대기 시작
                listenSocket.Listen(10);

                while (true)
                {
                    //작동 시작을 알린다.
                    Console.WriteLine("Listening...");

                    //Accept로 실질적으로 클라이언트를 입장시킨다.
                    //Accept 사용시 아무도 안들어온다면? -> Blocking을 사용하여 아래 코드는 아예 작동 자체를 안한다.
                    Socket clientSocket = listenSocket.Accept();

                    //수신
                    byte[] recvBuff = new byte[1024];
                    int recvBytes = clientSocket.Receive(recvBuff);
                    //수신시 몇 바이트인지 무결성을 검사하기 위해 사용, 문자열을 받을거라는 전제하에 만든 내용 나머지는 받지 못한다.
                    string recvData = Encoding.UTF8.GetString(recvBuff, 0, recvBytes);
                    Console.WriteLine($"[From Client] : {recvData}");

                    //전송, 수신과 반대순서로 간다.
                    byte[] sendBuff = Encoding.UTF8.GetBytes("Welcome to MMORPG Server");
                    clientSocket.Send(sendBuff);

                    //연결 종료
                    //연결 종료 전에 미리 예고한다.
                    clientSocket.Shutdown(SocketShutdown.Both);
                    //완전히 종료한다.
                    clientSocket.Close();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}
