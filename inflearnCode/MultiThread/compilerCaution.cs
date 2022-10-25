using System;
using System.Threading;
using System.Threading.Tasks;

//C#에서는 Release 모드에서 무슨일이 벌어질지 모르니 코드를 멀티쓰레딩에 맞게 잘 작성해야함
namespace ServerCore
{
    //VS에서 release 모드로 주로 배포를 실시하는데 -> 최적화가 적용됨 -> 코딩하기 드럽게 어려워짐
    class Program
    {
        volatile static bool _stop = false;
        //전역변수는 모든 쓰레드가 동시에 접근 가능하다.
        //volatile 키워드를 앞에 붙임으로써 최적화의 함정을 피해갈 수 있다
        //volatile : 휘발성이란 뜻, 언제 어떻게 변할지 모르니 최적화 과정에서 임의 개입을 하지 말것을 컴파일러에 알린다 C++에도 있지만 의미가 약간 다르다 C#에선 안쓰는 것을 추천.

        static void ThreadMain()
        {
            Console.WriteLine("쓰레드 시작");

            while (_stop == false)
            {
                //stop신호가 오기를 기다린다.
                //Release 모드에서는 여기서 무한루프에 빠져버린다 -> 멀티쓰레딩에선 엄청 자주 있는 일
                //최적화 과정에서 외부에서 간섭되는 코드를 파악하지 못하고 그냥 논리적으로 동일한 다른 내용으로 바꿔버린다
            }

            Console.WriteLine("쓰레드 종료");
        }

        static void Main(string[] args)
        {
            Task t = new Task(ThreadMain);
            t.Start();

            Thread.Sleep(1000);

            _stop = true;

            Console.WriteLine("Stop호출");
            Console.WriteLine("종료 대기중");
            t.Wait();
            //Thread의 Join과 같은 개념인 Wait

            Console.WriteLine("종료 성공");
        }
    }
}
