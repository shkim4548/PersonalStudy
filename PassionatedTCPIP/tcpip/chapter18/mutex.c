#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD 100
void *thread_inc(void *arg);
void *thread_des(void *arg);

long long num = 0;
pthread_mutex_t mutex;
//뮤텍스의 참조 값 저장을 위한 변수가 선언되었다. 전역변수로 선언된 이유는 뮤텍스가 thread_inc, thread_des 두개의 함수 내에서 이뤄진다.

int main(int argc, char *argv[])
{
    pthread_t thread_id[NUM_THREAD];
    int i;

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < NUM_THREAD; i++)
    {
        if (i % 2)
            pthread_create(&(thread_id[i]), NULL, thread_inc, NULL);
        else
            pthread_create(&(thread_id[i]), NULL, thread_des, NULL);
    }

    for (i = 0; i < NUM_THREAD; i++)
        pthread_join(thread_id[i], NULL);

    printf("result: %lld \n", num);
    pthread_mutex_destroy(&mutex);
    //뮤텍스의 소멸 -> 뮤텍스는 쓸모없어지면 반드시 소멸시켜야한다.
    return 0;
}

void *thread_inc(void *arg)
{
    int i;
    pthread_mutex_lock(&mutex);
    //가장 주목해야할 점은 lock과 unlock 과정 사이에 반복문이 같이 포함되어 있다.
    for (i = 0; i < 50000000; i++)
        num += 1;
        //임계영역은 위의 1행뿐
    pthread_mutex_unlock(&mutex);
    return NULL;
}
void *thread_des(void *arg)
{
    int i;
    for(i=0;i<50000000;i++){
        //이번엔 반복문 안에 lock과 unlock이 다 들어 있다.
        pthread_mutex_lock(&mutex);
        num-=1;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}