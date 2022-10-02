using System;
using System.Threading;
using System.Threading.Tasks;

namespace ServerCore
{
    //각 세션을 이용하여 lock이 여러개 사용되는 상황을 가정한다. -> 이 둘은 서로 왔다갔다 할 수 있다.
    //DeadLock의 가장 큰 문제는 개발단계에서 안잡히고 실서비스 중에 조지게 잡힌다.
    class SessionManager
    {
        //클래스 wrapping을 이용하여 id를 부여하여 Deadlock을 예방하는 lock을 만든다
        class FastLock
        {
            public int id;
            //id를 이용하여 DeadLock을 추적할 때 훨씬 편리하다. -> 배포 전에 발견하는데 큰 의미를 두는 것이 중요하다.
        }

        static object _lock = new object();

        public static void TestSession()
        {
            lock(_lock)
            {

            }
        }

        public static void Test()
        {
            lock (_lock)
            {
                UserManager.TestUser();
            }
        }
    }

    class UserManager
    {
        static object _lock = new object();
        public static void Test()
        {
            //Monitor.TryEnter() -> lock에 걸린 후 일정 시간이 지난 후 값이 안나오면 다른거 하거나 Error를 리턴하는 방법이다
            //근데 실패 자체가 lock 구조에 큰 문제가 있다는 의미이다.
            lock (_lock)
            {
                SessionManager.TestSession();
            }
        }

        public static void TestUser()
        {
            lock (_lock)
            {

            }
        }
    }


    class Program
    {
        static int number = 0;

        static object _obj = new object();

        static void Thread_1()
        {
            for (int i = 0; i < 10000; i++)
            {
                SessionManager.Test();
            }
        }

        static void Thread_2()
        {
            for (int i = 0; i < 10000; i++)
            {
                UserManager.Test();
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
