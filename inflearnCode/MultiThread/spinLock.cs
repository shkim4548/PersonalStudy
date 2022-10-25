using System;
using System.Threading;
using System.Threading.Tasks;

namespace ServerCore
{
    //spinLock은 면접 0순위 내용이다. 대충 lock을 획득할때까지 시도한다는 내용
    class SpinLock
    {
        //사용 여부를 알려주는 변수
        volatile int _locked = 0;
        public void Acquire()
        {
            /*
            //아래 locked가 true가 들어가는 부분까지가 직접적으로 문제가 되는 부분이다. -> 이 부분을 묶어줘야한다.
            while (_locked)
            {
                //잠금이 풀리기를 기다린다.
                
            }
            //잠금이 풀린 후 사용권을 가져온다.
            _locked = true;
            */
            /*
            //묶어준 버전이 아래와 같음(InterLocked.Exchange버전)
            while (true)
            {
                //레퍼런스로 location값을 넣어주고, 두번째 인자로 value를 제공
                //원본값(1번 인자)에다가 2번 인자를 대입연산한다.
                //이 값은 싱글 스레드처럼 사용되므로 단순한 모델로도 큰 문제가 없다.
                int original = Interlocked.Exchange(ref _locked, 1);
                if (original == 0)
                    break;
            }
            */
            //Interlocked.CompareExchange 사용버전
            while (true)
            {
                //결과값의 식별을 편하게 하기 위해 변수명을 사용 C++ 스타일로 구현하였다.
                int expected = 0; //예상값
                int desired = 1; //원하는 값 1로 대입하고 싶다

                //CAS : Compare And Swap 함수
                int original = Interlocked.CompareExchange(ref _locked, desired, expected);
                //예상값과 locked이 같다면 desired를 대입하라는 내용
                if (original == 0)
                {
                    break;
                }
            }
        }

        //Acquire를 통과했다면 큰 lock획득에 유일성을 담보했다는 의미이므로 나갈때는 큰 동작이 필요없다.
        public void Release()
        {
            _locked = 0;
        }
    }
    class Program
    {
        static int _num = 0;
        static SpinLock _lock = new SpinLock();

        static void Thread_1()
        {
            for(int i = 0; i < 1000000; i++)
            {
                _lock.Acquire();
                _num++;
                _lock.Release();
            }
        }

        static void Thread_2()
        {
            for(int i = 0; i < 1000000; i++)
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
