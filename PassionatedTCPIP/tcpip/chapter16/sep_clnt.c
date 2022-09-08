#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_addr;

    FILE *readfp;
    FILE *writefp;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    readfp = fdopen(sock, "r");
    //표준 입출력 함수의 호출을 위해 읽기모드, 쓰기모드 FILE 포인터를 생성하고 있다.
    writefp = fdopen(sock, "w");

    while (1)
    {
        if (fgets(buf, sizeof(buf), readfp) == NULL)
            break;
            //EOF가 전달되면 fgets 함수는 NULL 포인터를 반환한다. 따라서 NULL이 반환되는 경우에는 반복문을 빠져나간다.
        fputs(buf, stdout);
        fflush(stdout);
    }

    fputs("FROM CLIENT: Thank you \n", writefp);
    //서버로 마지막 문자열이 전송된다. 서버로부터 전송된 EOF 수신 후에 전송하는 문자열이다.
    fflush(writefp);
    fclose(writefp);
    fclose(readfp);
    return 0;
}