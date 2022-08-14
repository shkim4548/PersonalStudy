#include<stdio.h>
#include<unistd.h>
#include<signal.h>

/*
    signal을 이용하여 프로세스의 종료를 확인할 수 있다.
*/
void timeout(int sig){
    //시그널 핸들러 함수
    //시그널이 발생했을 때 호출되어야할 함수가 각각 정의되어 있다.
    if(sig==SIGALRM)
        puts("Time out");
    alarm(2);
    //2초 간격으로 SIGALRM 시그널을 반복 발생시키기 위해 시그널 핸들러 내에서 alarm함수를 호출한다.
}

void keycontrol(int sig){
    //시그널 핸들러 함수, 기능적으로는 위와 같다.
    if(sig==SIGINT)
        puts("CTRL+C pressed");
}

int main(int argc, char* argv[]){
    int i;
    signal(SIGALRM, timeout);
    //시그널 SIGALRM를 시그널 핸들러 등록
    signal(SIGINT, keycontrol);
    //시그널 SIGINT를 시그널 핸들러로 등록한다.
    alarm(2);

    for(i=0;i<3;i++){
        puts("wait...");
        sleep(100);
        //시그널 핸들러의 실행을 확인하기 위해 slepp을 건다 100초 3회 이지만 굉장히 빨리 끝난다.
    }
    return 0;
}