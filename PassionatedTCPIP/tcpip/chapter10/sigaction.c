#include<stdio.h>
#include<unistd.h>
#include<signal.h>

//시그널 함수와 달리 sigaction은 OS에 따라 동작방식에 차이를 보이지 않는다.
void timeout(int sig){
    //시그널 핸들러
    if(sig==SIGALRM)
        puts("Timeout!");
    alarm(2);
}

int main(int argc, char* argv[]){
    int i;
    struct sigaction act;
    //시그널 발생시 호출될 함수의 등록을 위해서 sigaction 구조체 변수를 선언하여 멤버인 sa_handler에 함수 포인터 값을 저장해야한다.
    act.sa_handler=timeout;
    sigemptyset(&act.sa_mask);
    //sigaction 구조체 멤버 sa_mask의 모든 비트를 0으로 초기화하기 위한 함수호출
    act.sa_flags=0;
    //sa_flags는  signal 함수를 대신하기 위해서 필요한 멤버가 아니므로 0으로 초기화한다.
    sigaction(SIGALRM, &act, 0);

    alarm(2);

    for(i=0; i<3; i++){
        puts("wait...");
        sleep(100);
    }
    return 0;
}