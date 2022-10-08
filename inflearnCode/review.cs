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
        static Mutex _lock3 = new Mutex(); // 같은 프로그램이 아니라고 해도 순서를 맞추는 작업을 할 수 있다. -> 커널단위에서 움직이니까, 그런데 게임서버 단위에선 움직이지 않는다.

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
