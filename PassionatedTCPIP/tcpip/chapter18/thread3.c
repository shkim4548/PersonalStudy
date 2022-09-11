//워커쓰레드 모델구현, 두 쓰레드가 하나의 전역변수 sum에 직접 접근한다.
#include <stdio.h>
#include <pthread.h>
void *thread_summation(void *arg);
int sum = 0;
//두 쓰레드가 동시접근 가능한 전역변수

int main(int argc, char *argv[])
{
    pthread_t id_t1, id_t2;
    int range1[] = {1, 5};
    int range2[] = {6, 10};

    pthread_create(&id_t1, NULL, thread_summation, (void *)range1);
    pthread_create(&id_t2, NULL, thread_summation, (void *)range2);

    pthread_join(id_t1, NULL);
    pthread_join(id_t2, NULL);
    printf("result: %d \n", sum);
    return 0;
}

void *thread_summation(void *arg)
{
    int start = ((int *)arg)[0];
    int end = ((int *)arg)[1];

    while (start <= end)
    {
        sum += start;
        start++;
    }
    return NULL;
}