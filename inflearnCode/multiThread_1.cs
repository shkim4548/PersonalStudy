using System;
using System.Threading;
using System.Threading.Tasks;

//C#에서는 쓰레드 객체를 직접 만들어서 관리할 일 자체가 잘 없다. ThreadPool과 Task로 처리가능
namespace ServerCore
{
    class Program
    {
        static void MainThread(object state)
        {
            //함수의 파라미터는 쓰레드의 실행을 위해 지정한 임의의 파라미터
            for (int i = 0; i < 5; i++)
                Console.WriteLine("Hello thread!");
        }

        static void Main(string[] args)
        {
            Task t = new Task(() => { while (true) { } }, TaskCreationOptions.LongRunning);
            t.Start();
            //쓰레드 풀의 단점 극복가능한 물건, 관리는 ThreadPool 내부에서 진행
            //단 option을 더 붙일 수 있다 while 문 이후에 붙은 내용들이 옵션에 해당, LongRunning을 사용시 쓰레드 풀의 과부하 해결 가능

            ThreadPool.SetMinThreads(1, 1);
            //1번 파라미터가 workerThread 2번은 본 강의에선 생략
            ThreadPool.SetMaxThreads(5, 5);
            //위의 두 줄로 최소 스레드 1 최대 스레드 5로 지정한다.

            //for(int i = 0; i < 3; i++)
            //    ThreadPool.QueueUserWorkItem ((obj) => { while (true) { }});
            //여기서 i<5일 경우 모든 풀 내부의 쓰레드를 다 잡아서 아래의 ThreadPool을 고의로 망가뜨린다.
            //다시 말해 하나라도 남으면 아래의 ThreadPool이 작동한다
            

            //ThreadPool을 생성하여 실행시 바로 종료된다 -> 백그라운드에서 돌아가는 Thread이다
            ThreadPool.QueueUserWorkItem(MainThread);
            //threadPool을 이용하여 객체를 생성 종료가 아니라 생성 및 대기상태로 사용한다.
            //마냥 좋지많은 않다 -> 만약 무한 루프 한군데에 잡히거나 장기간을 요구하는 내용에 사용시 작업 자체가 뻗어버릴 수 있다.


            /*
            //아래 for문은 쓰레드 객체와 context switching에서 가장 안좋은 예시
            for (int i = 0; i < 1000; i++)
            {
                ////별도의 쓰레드 객체 생성
                Thread t = new Thread(MainThread);
                ////쓰레드의 실행 지점, C#은 포어그라운드에서 쓰레드가 실행된다 -> 실행 상위 함수와 독립적으로 실행
                t.Name = "test Thread";
                t.IsBackground = false;
                t.Start();
            }
            */
            //Console.WriteLine("Waiting for Thread");
            ////끝날때까지 기다린다는 소리
            //t.Join();



            //Console.WriteLine("Hello World!");
            ////함수 종료와 동시에 쓰레드도 종료된다.
            while (true)
            {

            }
            //위의 while문을 작동 시킴으로써 백그라운드 작동을 확인 -> 그런데 main함수가 무한루프니까 쓰레드 작동 후 무한 대기
        }
    }
}
