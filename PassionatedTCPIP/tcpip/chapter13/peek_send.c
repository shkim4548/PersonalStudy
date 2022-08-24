#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/socket.h>
#include<arpa/inet.h>
void error_handling(char* message);

int main(int argc, char* argv[]){
    int sock;
    struct sockaddr_in send_adr;
    if(argc!=3){
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }
    
    sock=socket(PF_INET, SOCK_STREAM, 0);
    memset(&send_adr, 0, sizeof(send_adr));
    send_adr.sin_family=AF_INET;
    send_adr.sin_addr.s_addr=inet_addr(argv[1]);
    send_adr.sin_port=htonl(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&send_adr, sizeof(send_adr))==-1)
        error_handling("connect() error");
        //위의 if문에서 연결 요청을 진행 -> 아래의 write함수에서 "123"을 전송한다.

    write(sock, "123", strlen("123"));
    close(sock);
    return 0;
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}