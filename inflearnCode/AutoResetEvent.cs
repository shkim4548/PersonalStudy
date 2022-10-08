using System;
using System.Threading;
using System.Threading.Tasks;

namespace ServerCore
{
    class Lock
    {
        //커널 입장에선 bool하나 선언한 것과 유사한 개념
        AutoResetEvent _available = new AutoResetEvent(true);
        //AutoResetEvent 객체 생성시 파라미터 true -> availiable
        //                                    false -> non-available
        //문닫기는 자동으로 해준다. 통과 허가 여부만 결정되는 것이다
        public void Acquire()
        {
            _available.WaitOne();//입장시도 true면 바로 들어올거고 아니면 못들어온다
            //_available.Reset(); //WaitOne에 포함된 개념 -> 다시 닫기라고 생각하면 된다.
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
            for (int i = 0; i < 10000; i++)
            {
                _lock.Acquire();
                _num++;
                _lock.Release();
            }
        }

        static void Thread_2()
        {
            for (int i = 0; i < 10000; i++)
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
