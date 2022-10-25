using System;
using System.Threading;
using System.Threading.Tasks;


//메모리 베리어
//1. 하드웨어 차원에서의 임의적인 코드 재배치의 억제
//2. 가시성의 확보

//1. Full Memory Barrier -> Store과 Load 모두를 막는다.
//2. Store Memory Barrier -> Store만 막는다
//3. Load Memory Barrier -> Load만 막는다

//가시성
//

namespace ServerCore
{
    class Program
    {
        static int x = 0;
        static int y = 0;
        static int r1 = 0;
        static int r2 = 0;

        static void Thread_1()
        {
            y = 1; //Store
            Thread.MemoryBarrier();
            //여기에 경계선을 그어서 하드웨어가 순서를 맘대로 어기지 못하게 한다
            
            r1 = x; //Load
        }

        static void Thread_2()
        {
            x = 1;
            Thread.MemoryBarrier();
            //위의 1번 쓰레드에서 배리어를 사용했다면 짝을 맞춰서 실행해줘야 가시성에서 동기화가 진행됨

            r2 = y;
        }


        static void Main(string[] args)
        {
            int count = 0;
            while (true)
            {
                count++;
                x = y = r1 = r2 = 0;

                Task t1 = new Task(Thread_1);
                Task t2 = new Task(Thread_2);

                t1.Start();
                t2.Start();

                Task.WaitAll(t1, t2);
                if (r1 == 0 || r2 == 0)
                    break;
            }
            Console.WriteLine($"{count}번 안에 빠져나온다");
        }
    }
    //하드웨어 상에서 작업을 진행할때 CPU는 작업 최적화를 위해서 막 순서를 바꿔버리는 수가 있다.
}
