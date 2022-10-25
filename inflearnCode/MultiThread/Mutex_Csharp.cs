using System;
using System.Threading;
using System.Threading.Tasks;

namespace ServerCore
{
    //커널수준에서 Lock을 구현하기 -> Mutex
    //커널수준에서 구현하기 때문에 느리다.
    class Program
    {
        //SpinLock에 비해서 엄청 느리단걸 확인 가능 100000은 아예 답이 늦게 나올정도로 느리다.
        static int _num = 0;
        static Mutex _lock = new Mutex();

        static void Thread_1()
        {
            for(int i = 0; i < 10000; i++)
            {
                _lock.WaitOne();
                _num++;
                _lock.ReleaseMutex();
            }
        }

        static void Thread_2()
        {
            for(int i = 0; i < 10000; i++)
            {
                _lock.WaitOne();
                _num--;
                _lock.ReleaseMutex();
            }
        }

        static void Main(string[] args)
        {
            Task t1 = new Task(Thread_1);
            Task t2 = new Task(Thread_2);

            t1.Start();
            t2.Start();

            Task.WaitAll(t1, t2);

            Console.WriteLine(_num);
        }
    }
}
