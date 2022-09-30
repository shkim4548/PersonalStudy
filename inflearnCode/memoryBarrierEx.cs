using System;
using System.Threading;
using System.Threading.Tasks;


//메모리 베리어
//아래의 베리어 4개가 모두 있어야 의도대로 작동한다.

namespace ServerCore
{
    class Program
    {
        int _answer;
        bool _complete;

        void A()
        {
            _answer = 123; //Store
            Thread.MemoryBarrier(); //Barrier 1 -> 위의 Store가 발생했고 -> 캐싱된 메모리를 한번 메모리로 넘겨주고
            _complete = true; //Store
            Thread.MemoryBarrier(); //Barrier 2 -> 위의 Store가 발생했고 -> 캐싱된 메모리를 한번 메모리로 넘겨주고
        }

        void B()
        {
            Thread.MemoryBarrier(); //Barrier 3 -> Load가 발생할 예정이므로 한번 더 메모리를 긁어온다.
            if (_complete)
            {
                Thread.MemoryBarrier(); //Barrier 4 -> 최신정보를 긁어오는지 확인하기 위해 마지막으로 캐싱된 메모리를 작성
                Console.WriteLine(_answer);
            }
        }

        static void Main(string[] args)
        {
        }
    }
    //하드웨어 상에서 작업을 진행할때 CPU는 작업 최적화를 위해서 막 순서를 바꿔버리는 수가 있다.
}
