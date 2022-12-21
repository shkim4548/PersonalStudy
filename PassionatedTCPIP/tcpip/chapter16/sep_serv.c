#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    FILE *readfp;
    FILE *writefp;

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;
    char buf[BUF_SIZE] = {
        0,
    };

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr));
    listen(serv_sock, 5);
    clnt_adr_sz = sizeof(clnt_adr);
    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);

    readfp = fdopen(clnt_sock, "r");
    // clnt_sock에 저장된 파일 디스크립터를 기반으로 읽기모드 FILE 포인터를 생성
    writefp = fdopen(clnt_sock, "w");
    // clnt_sock에 저장된 파일 디스크립터를 기반으로 쓰기모드 FIEL 포인터를 생성

    fputs("FROM SERVER: Hi~ client?\n", writefp);
    fputs("I love all of the world \n", writefp);
    fputs("You are awesome! \n", writefp);
    fflush(writefp);
    //클라이언트로 문자열을 전송한 후 fflush 함수 호출하여 전송을 마무리

    fclose(writefp);
    //쓰기모드 FILE포인터를 대상으로 fclose 함수를 호출하고 있다 -> 이를 통해 상대방 호스트에게 EOF를 전송
    fgets(buf, sizeof(buf), readfp);
    //클라이언트가 EOF를 수신한 후에 보내는 문자열 -> 당연하지만 클라이언트는 이 문자열을 수신하지 못함
    fputs(buf, stdout);
    fclose(readfp);
    return 0;
}