using System;
using System.Threading;
using System.Threading.Tasks;

namespace ServerCore
{
    class Program
    {
        //저번에 했던 메모리 베리어 말고 Lock 등의 더 우아한 방식이 있다.
        //10000까지는 수학적으로 합당한 답이 나오는데 100000부터 이상한 수가 나온다. 가시성 문제는 아니다
        //interlocked 계열은 메모리 베리어가 간접적으로 작동하므로 volitile등을 사용하지 않아도 된다.
        static int number = 0;

        static void Thread_1()
        {
            //atomic == 원자성 -> 쪼갤 수 없는 최소한의 작업으로 쪼개서 실행하기 때문에 세단계에 걸쳐서 다룬다. -> 여기서 문제가 발생한다.
            for(int i = 0; i < 100000; i++)
            {
                //all or noting 전부 작동이 되거나 아예 안되거나 -> 1번 작업이 확실히 완료되야 2번 작업이 실시된다. -> 순서가 확실히 보장된다.
                Interlocked.Increment(ref number); //작업을 원자적으로 실행되도록 한다 -> 단 성능상 희생이 크니까 사용시 주의해야한다.
                //파라미터를 주소값으로 제공한다 -> 해당 시간에 유일하게 접근해야하므로 복사를 실행하는 call by value는 옳지 않다.
                //number++;
                //number++가 실제로 실행되는 순서는 이하와 같다.
                //int tmp = number;
                //tmp += 1;
                //number = tmp;
                //세 단게에 걸쳐 주소에 접근 -> 덧셈연산 실행 -> 본주소로 복귀
            }
        }
        static void Thread_2()
        {
            for(int i = 0; i < 100000; i++)
            {
                //number--;
                Interlocked.Decrement(ref number);
            }
        }

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
