using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.Encodings;

namespace DummyClient
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //DNS(Domain Name System) : 서버 도메인 주소를 IP
            // IP로 서버 주소를 줬을 때 유동 IP의 경우 자동으로 변경된 IP가 적용되지 않는다. -> 도메인 네임을 등록 후 그에 맞는 IP를 바인딩해준다
            string host = Dns.GetHostName();
            IPHostEntry ipHost = Dns.GetHostEntry(host);
            IPAddress ipAddr = ipHost.AddressList[0];
            IPEndPoint endPoint = new IPEndPoint(ipAddr, 7777);//(IP주소, port 번호)

            //socket 초기화
            Socket socket = new Socket(endPoint.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            try
            {
                //listen()중인 서버에 accept를 요청한다.
                //Connect 함수는 블로킹 계열 함수 -> 게임에서 써서는 안됀다. 서버가 안받아주면 상당히 오래 대기한다.
                socket.Connect(endPoint);
                Console.WriteLine($"Connected To {socket.RemoteEndPoint.ToString()}");

                //서버로 발송
                byte[] sendBuff = Encoding.UTF8.GetBytes("Hello World!");
                //블로킹 계열 함수
                int sendBytes = socket.Send(sendBuff);

                //서버로부터 수신
                byte[] recvBuff = new byte[1024];
                //블로킹 계열 함수
                int recvBytes = socket.Receive(recvBuff);
                string recvData = Encoding.UTF8.GetString(recvBuff, 0, recvBytes);
                Console.WriteLine($"[From Server] : {recvData}");

                //소켓 연결 종료
                socket.Shutdown(SocketShutdown.Both);
                socket.Close();
                //클라는 볼일 끝나면 꺼지고(현재 설정상) 서버는 계속 while 루프를 돈다(현재 설정 상)
            }
            catch(Exception e)
            {
                Console.WriteLine(e.ToString());
            }
            
           
        }
    }
}
