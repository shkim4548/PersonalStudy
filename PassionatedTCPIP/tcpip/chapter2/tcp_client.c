#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *messgae);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len = 0;
    int idx = 0, read_len = 0;

    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    // TCP 소켓을 생성하는 부분, 3번인자에 0이 들어간 것을 확인가능
    memset(&serv_addr, 0, sizeof(serv_addr));
    // 메모리를 지정한 문자로 채워버린다. 여기선 메모리를 0으로 초기화 해버리는 방법이된다.
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    while (read_len = read(sock, &message[idx++], 1))
    {
        // while 문 내부에서 read함수를 반복호출중이다. 실행시마다 1바이트씩 데이터를 읽어들인다.
        //이렇게 가서 끝에선 0을 읽기때문에 false가 되어 while문이 종료된다
        if (read_len == -1)
            error_handling("read() error");
        str_len += read_len;
    }
    printf("Message from server: %s \n", message);
    printf("Function read call count : %d \n", str_len);
    close(sock);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}