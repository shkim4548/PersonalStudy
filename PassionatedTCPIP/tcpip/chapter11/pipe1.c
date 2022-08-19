#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30

//단방향 데이터 파이프라인
int main(int argc, char* argv[]){
    int fds[2];
    char str[]="Who are you";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds);
    //pipe 함수 호출을 통해서 파이프를 생성한다. 이로 인해 fds애는 입출력을 위한 파일 디스크립터가 생성된다
    pid=fork();
    //pipe 함수호출 이후 바로 fork함수를 호출한다. 여기서 자식 프로세스는 두개의 파일 디스크립터를 가진다. 파이프가 아니라 파이프의 파일 디스크립터를 소유한 것이다.
    if(pid==0){
        write(fds[1], str, sizeof(str));
        //자식 프로세스는 write함수를 호출하여  파이프로 문자열을 전달한다.
    }
    else{
        read(fds[0], buf, BUF_SIZE);
        //파이프로부터 문자열을 수신한다.
        puts(buf);
    }
    return 0;
}