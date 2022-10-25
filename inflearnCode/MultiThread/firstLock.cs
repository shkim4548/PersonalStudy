using System;
using System.Threading;
using System.Threading.Tasks;

namespace ServerCore
{
    class Program
    {
        static int number = 0;

        static object _obj = new object();

        static void Thread_1()
        {
            for(int i = 0; i < 100000; i++)
            {
                lock (_obj)
                {
                    //내부적으로는 Monitor.Enter로 기능하지만 훨씬 구문 작성이 간결해진다.
                    number++;
                }
                //상호 배제 상황에 대한 설명
                //Monitor.Enter(_obj); //사용중인 화장실의 문을 잠가버리기
                //number++;           //작업 내용 -> 이 블럭 안의 내용은 싱글쓰레드 취급하고 작성해도 무방하다.
                //Monitor.Exit(_obj); //사용후의 화장실의 문을 다시 열기

                //Enter와 Exit를 일일이 사용할 경우 -> 관리가 귀찮아진다 + 코드가 드럽다
                //예를 들어 실수로 Exit 전에 return을 시켜버릴 경우(DeadLock 현상, 대충 야마났단 소리)

                //해결책으로는 try - catch - finally 구문을 사용하면 예외 발생시의 해결책 중 하나가 될 수 있다.
            }
        }

        static void Thread_2()
        {
            for(int i = 0; i < 100000; i++)
            {
                Monitor.Enter(_obj);
                number--;
                Monitor.Exit(_obj);
            }
        }

        //interlock 계열의 raceCondition 조절은 정수만 사용 가능하다는 치명적인 단점이 있다.
        static void Main(string[] args)
        {
            Task t1 = new Task(Thread_1);
            Task t2 = new Task(Thread_2);

            t1.Start();
            t2.Start();

            Task.WaitAll(t1, t2);

            Console.WriteLine(number);
        }
    }
}
