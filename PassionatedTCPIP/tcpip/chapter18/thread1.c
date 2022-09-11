#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *thread_main(void *arg);

int main(int argc, char *argv[])
{
    pthread_t t_id;
    int thread_param = 5;

    if (pthread_create(&t_id, NULL, thread_main, (void *)&thread_param) != 0)
    {
        //thread_main 함수의 호출을 시작으로 별도의 실행흐름을 구성하는 쓰레드를 요청한다
        //thread_main 함수 호출시 임자로 변수 thread_param의 주소값을 전달하고 있다.
        puts("pthread_create() error");
        return -1;
    };
    sleep(10);
    //sleep함수의 호출을 통해서 main함수의 실행을 10초간 중지시킨다.
    puts("end of main");
    return 0;
}

void *thread_main(void *arg)
{
    //매개변수 arg로 전달되는 것은 pthread_create 함수의 네번째 전달인자이다.
    int i;
    int cnt = *((int *)arg);
    for (i = 0; i < cnt; i++)
    {
        sleep(1);
        puts("running thread");
    }
    return NULL;
}