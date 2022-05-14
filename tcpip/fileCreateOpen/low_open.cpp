#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>//파일 읽고 쓰기를 위한 c헤더
#include<unistd.h>//유닉스 컴파일러를 불러오기 위한 헤더파일

void error_handling(char* message);

int main(void){
    int fd;
    char buf[] = "Let's go!\n";
    fd=open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);
    //파일 오픈 모드 지정
    //O_CREAT : 위의 파일명은 data.txt가 없으면 새로 만들어라
    //O_WRONLY : 쓰기가능으로 열것
    //O_TRUNC : 파일을 생성할 때 이미 있는 파일이고, 쓰기 옵션으로 열었으면 내용을 모두 지우고 파일의 길이를 0으로 변경한다.
    
    if(fd==1)
        error_handling("open() error!");

    printf("file descriptor: %d\n", fd);

    if(write(fd, buf, sizeof(buf))==-1)
        error_handling("write() error");

    close(fd);
    return 0;
}

void error_handling(char *message){
    fputs(message, stderr);
    fputc('\n',stderr);
    exit(1);
}