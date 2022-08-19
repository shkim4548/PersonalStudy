#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30

int main(int argc, char* argv[]){
    int fds1[2], fds2[2];
    char str1[]="Who are you";
    char str2[]="Thank you for your message";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds1), pipe(fds2);
    //두개의 파이프를 동시에 생성한다.
    pid=fork();
    if(pid==0){
        write(fds1[1], str1, sizeof(str1));
        //자식 프로세스에서 부모프로세스로의 데이터 전송 배열 fds1이 참조하는 파이프를 통해서 이뤄진다
        read(fds2[0], buf, BUF_SIZE);
        //부모 프로세스에서 자ㅣ식 프로세스로의 데이터 전송은 배열 fds2가 참조하는 파이프를 통해서 이뤄진다
        printf("Child proc output: %s \n", buf);
    }
    else{
        read(fds1[0], buf, BUF_SIZE);
        //자식 프로세스에서 부모프로세스로의 데이터 전송은 배열 fds1이 참조하는 퍼이프를 통해서 이뤄진다.
        printf("Parent proc output: %s \n", buf);
        write(fds2[1], str2, sizeof(str2));
        //부모 프로세스에서 자식프로세스로의 데이터 전송은 배열 fds2가 참조하는 파이프를 통해서 이뤄진다.
        sleep(3);
        //앞의 소스와 동일한 이유로 들어가 있다.
    }
    return 0;
}