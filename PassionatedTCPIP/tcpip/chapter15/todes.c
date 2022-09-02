#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    FILE *fp;
    int fd = open("data.dat", O_WRONLY | O_CREAT | O_TRUNC);
    //반환된 파일 디스크립터의 정수값을 출력하고 있다.
    if (fd == -1)
    {
        fputs("file open error", stdout);
        return -1;
    }

    printf("First file descriptor: %d \n", stdout);
    fp = fdopen(fd, "w");
    // fdopen 함수호출을 통해서 파일 디스크립터를 FILE 포인터로 변환한다.
    fputs("TCP/IP SOCKET PROGRAMMING \n", fp);
    printf("Second file descriptor: %d \n", fileno(fp));
    // fileno 함수호출을 통해서 이를 다시 파일 디스크립터로 변환하였다. 그리고 이 정수값을 출력하였다.
    fclose(fp);
    return 0;
}