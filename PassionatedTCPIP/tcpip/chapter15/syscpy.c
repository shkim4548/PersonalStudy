#include <stdio.h>
#include <fcntl.h>
#define BUF_SIZE 3 //배열의 길이를 최소한으로 정의한다.

int main(int argc, char *argv[])
{
    int fd1, fd2; //파일 디스크립터를 저장한다.
    int len;
    char buf[BUF_SIZE];

    fd1 = open("news.txt", O_RDONLY);
    fd2 = open("cpy.txt", O_WRONLY | O_CREAT | O_TRUNC);

    while ((len = read(fd1, buf, sizeof(buf))) > 0)
        write(fd2, buf, len);

    close(fd1);
    close(fd2);
    return 0;
}
/*
    read&write 함수 기반의 파일복사 프로그램이다.
    txt 파일 이외의 파일은 사용하지 않는다.
*/