using System;
using System.Threading;
using System.Threading.Tasks;

namespace ServerCore
{
    class Lock
    {
        //Lock을 구현하는데 ManualResetEvent를 사용하는건 적절하지 않다. -> 모든 이벤트를 false로 만들어서 다 완료된 후에 true로 전환하는 내용 사용시 유리하다.
        ManualResetEvent _available = new ManualResetEvent(false);
        public void Acquire()
        {
            _available.WaitOne(); // 입장시도
            _available.Reset(); // 입장 후 문을 닫는다(수동) -> 의도한 결과인 0이 나오지 않는다.
        }

        public void Release()
        {
            _available.Set();
            //지나가고 나서 다시 열어준다(signal상태로 만든다.) flag state -> true로 전환
        }
    }



    class Program
    {
        //SpinLock에 비해서 엄청 느리단걸 확인 가능 100000은 아예 답이 늦게 나올정도로 느리다.
        static int _num = 0;
        static Lock _lock = new Lock();

        static void Thread_1()
        {
            for(int i = 0; i < 10000; i++)
            {
                _lock.Acquire();
                _num++;
                _lock.Release();
            }
        }

        static void Thread_2()
        {
            for(int i = 0; i < 10000; i++)
            {
                _lock.Acquire();
                _num--;
                _lock.Release();
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
