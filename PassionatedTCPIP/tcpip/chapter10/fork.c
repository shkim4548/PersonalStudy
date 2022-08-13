#include<stdio.h>
#include<unistd.h>

int gval=10;
//기본적으로 fork 함수는 프로세스를 생성하기 위해 사용한다.
int main(int argc, char* rgv[]){
    pid_t pid;
    int lval=20;
    gval++, lval+=5;

    pid=fork();
    //자식 프로세스를 생성한다. -> 부모 프로세스ID = 자식 프로세스의 ID & 자식 프로세스 ID = 0
    if(pid==0)
        gval+=2, lval+=2;
    else
        gval-=1, lval-=2;

    if(pid==0){
        printf("Child Proc: [%d %d] \n", gval, lval);
        //자식 프로세스는 위의 문장이 실행된다 fork()함수에서 자식 프로세스에는 ID 0이 저장되었기 때문
    }
    else{
        printf("Parent Proc: [%d %d] \n", gval, lval);
    }
    return 0;

    // 위 프로그램의 결과 : parent process와 child process의 메모리는 완전히 분리되어 있다는 사실을 알 수 있다.
}