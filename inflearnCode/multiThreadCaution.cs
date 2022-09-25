using System;
using System.Threading;
using System.Threading.Tasks;

//C#에서는 Release 모드에서 무슨일이 벌어질지 모르니 코드를 멀티쓰레딩에 맞게 잘 작성해야함
namespace ServerCore
{
    //VS에서 release 모드로 주로 배포를 실시하는데 -> 최적화가 적용됨 -> 코딩하기 드럽게 어려워짐
    class Program
    {
        static void Main(string[] args)
        {
            int[,] arr = new int[10000, 10000];
            {
                long now = DateTime.Now.Ticks;
                for (int y = 0; y < 10000; y++)
                    for (int x = 0; x < 10000; x++)
                        arr[y, x] = 1;
                long end = DateTime.Now.Ticks;
                Console.WriteLine($"(y,x)가 걸린시간 {end - now}");
            }
            {
                long now = DateTime.Now.Ticks;
                for (int y = 0; y < 10000; y++)
                    for (int x = 0; x < 10000; x++)
                        arr[x, y] = 1;
                long end = DateTime.Now.Ticks;
                Console.WriteLine($"(y,x)가 걸린시간 {end - now}");
            }
            //이상하게 시간차이가 많이 난다. -> 캐시에서 발생한 문제
            //Special locality철학에 따라 공간적 유사성에 따라 선언된 배열 중 빈구간에도 미리 캐싱해버린다
            //따라서 두번째에서는 각 2차원 배열의 1,n에 가장 우선적으로 접근하기 때문에 캐싱에 따라 드릅게 느려진다.
        }
    }
}
