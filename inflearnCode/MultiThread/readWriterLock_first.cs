using System;
using System.Threading;
using System.Threading.Tasks;

namespace ServerCore
{
    class Program
    {
        // spinLock : 근성
        // Thread.Sleep(), Thread.Yield() : 양보 
        // AutoResetEvent, ManualResetEvent :갑질
        // 기본적인 작동 원리는 상호 배제이다.(Mutual exclusive)
        static object _lock = new object();
        static SpinLock _lock2 = new SpinLock();

        //서버에서 reward를 줘보기

        class Reward
        {

        }

        //서버에서 리워드 변경은 사실 거의 사용할 일 없는 부분이 된다. 근데 또 없으면 안됀다 -> RWLock(Reader/Writer Lock)
        static ReaderWriterLockSlim _lock3 = new ReaderWriterLockSlim(); //slim붙은거 더 최신형이다.


        // 더 일반적인 경우 -> 한번에 많은 쓰레드가 접근 가능하다.
        static Reward GetRewardById(int id)
        {
            _lock3.EnterReadLock();
            _lock3.ExitReadLock();
            
            lock (_lock)
            {

            }

            return null;
        }

        //더 특수한 경우
        void AddReward(Reward reward)
        {
            _lock3.EnterWriteLock();
            _lock3.ExitWriteLock();
        }


        static void Main(string[] args)
        {
            lock (_lock)
            {
                
            }
            bool lockTaken = false;
            try
            {
                _lock2.Enter(ref lockTaken);
            }
            finally
            {
                if (lockTaken)
                    _lock2.Exit();
                //상대방이 너무 오래잡고 있을 때 풀어버리기
            }
        }
    }
}
