#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[]){
    //argc: main함수에 전달되는 데이터의 길이
    //argv: main함수에 전달되는 실질적인 데이터, 동적 배열의 포인터로 제공된다.
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len;

    if(argc!=3){
        printf("Useage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }
    
    sock=socket(PF_INET, SOCK_STREAM, 0);
    if(sock==-1)
        error_handling("socket() error");
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    serv_addr.sin_port=htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
        error_handling("connect() error");

    str_len=read(sock, message, sizeof(message)-1);
    if(str_len==-1)
        error_handling("read() error");
    
    printf("Message from server : %s\n", message);
    close(sock);
    return 0;
}

void error_handling(char *message){
    fputs(message, stderr);//fputs는 문자열 배열을 출력할 때 사용한다
    fputc('\n', stderr); // fputc는 파일 입출력시에 사용한다.
    exit(1);
}