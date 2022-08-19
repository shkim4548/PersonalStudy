#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30

//양방향 데이터 파이프라인
int main(int argc, char* argv[]){
    int fds[2];
    char str1[]= "Who are you";
    char str2[]="Thank you for your message";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds);
    pid=fork();

    if(pid==0){
        //자식 프로세스의 실행 영역 
        write(fds[1], str1, sizeof(str1)); //데이터 송신부
        sleep(2);
        read(fds[0], buf, BUF_SIZE); //데이터 수신부
        printf("Child proc output: %s \n", buf);
    }
    else{
        //부모 프로세스의 실행 영역
        read(fds[0], buf, BUF_SIZE); //데이터 수신 from 자식 프로세스
        printf("Parent proc output: %s \n", buf);
        write(fds[1], str2, sizeof(str2)); //데이터 송신 to 자식 프로세스
        sleep(3); //프로세스가 끝나기 전에 CMD가 뜨는 것을 방지하기 위한 명령
    }
    return 0;
}

//결과는 문제가 발생한다, 2초의 지연시간이 발생하여 