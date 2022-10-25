using System;
using System.Threading;
using System.Threading.Tasks;

namespace ServerCore
{
    //재귀적 락을 허용할 것인가 -> 일단 여기선 쉽게갈려고 불허
    //스핀락 5000번 반복 후 Yield
    class Lock
    {
        //비트 플래그 선언
        const int EMPTY_FLAG = 0x00000000;
        const int WRITE_MASK = 0x7FFF0000;
        const int READ_MASK = 0x0000FFFF;

        const int MAX_SPIN_COUNT = 5000;
        // 32비트 구성 : [사용안함(1bit)] [WriteThreadId(15bit)] [ReadCount(16bit)]
        //WriteLock은 한번에 한쓰레드만 가질 수 있다.
        int _flag = EMPTY_FLAG; //시작값을 0으로 맞춘다.
        int _writeCount = 0;    //이미 상호 배타적이므로 멀티쓰레드를 고려할 필요는 없는 변수
        

        public void WriteLock()
        {
            int lockThreadId = (_flag & WRITE_MASK) >> 16;
            if (Thread.CurrentThread.ManagedThreadId == lockThreadId)
            {
                _writeCount++;
                return;
            }

            int desired = (Thread.CurrentThread.ManagedThreadId << 16) & WRITE_MASK; //WriteThreadId를 가져오기 위해 사용 1부터 쭉 늘어나는 코드

            //마우도 WriteLock or ReadLock을 획득하지 않을 때, 경합해서 소유권을 얻는다
            while (true)
            {

                for(int i = 0; i < MAX_SPIN_COUNT; i++)
                {
                    //시도 후 성공시 return
                    if (Interlocked.CompareExchange(ref _flag, desired, EMPTY_FLAG) == EMPTY_FLAG) //좌측 조건 만족시 성공이다.
                    {
                        _writeCount = 1;
                        return;
                    }
                    /*if (_flag == EMPTY_FLAG)    //아무도 lock을 갖지 않음 -> empty
                    {
                        _flag = desired; 
                        //여기서 결과는 원하는 값이 flag에 들어가지 않는다 -> 경합조건이 발생하기 때문 -> interlock계열을 사용하여 하나로 뭉쳐버려야한다.
                    }*/
                }
                //실패시 Yield
                Thread.Yield();
            }
        }

        public void WriteUnlock()
        {
            //초기상태로 돌려버린다.
            int lockCount = --_writeCount;
            if (lockCount == 0)
                Interlocked.Exchange(ref _flag, EMPTY_FLAG);
        }

        public void ReadLock()
        {
            int lockThreadId = (_flag & WRITE_MASK) >> 16;
            if (Thread.CurrentThread.ManagedThreadId == lockThreadId)
            {
                Interlocked.Increment(ref _flag);
                return;
            }

            //아무도 WriteLock을 획득하지 않으면 ReadCount를 1 올린다.
            while (true)
            {
                for(int i = 0; i < MAX_SPIN_COUNT; i++)
                {
                    int expected = (_flag & READ_MASK); //예상값 -> ReadMask == readCount 16비트 부분
                    if (Interlocked.CompareExchange(ref _flag, expected + 1, expected) == expected)
                        return;     //아래 if문 내용을 완전히 포함함

                    /*if((_flag & WRITE_MASK) == 0)//아무도 WriteLock을 가지지 않았다는 것을 보여주는 부분
                    {
                        _flag = _flag + 1;
                        //여기서 넘기기 직전에 누군가 WriteLock을 잡아버리면 문제가 발생한다. -> 여기도 한번에 처리해야한다 -> Interlocked 계열 다시 사용
                        return;
                    }*/
                }
                Thread.Yield();
            }
        }

        public void ReadUnlock()
        {
            Interlocked.Decrement(ref _flag);
        }
    }

    class Program
    {
        
        static void Main(string[] args)
        {
            
        }
    }
}
