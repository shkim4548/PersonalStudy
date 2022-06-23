#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define BUF_SIZE 1024
void error_handling(char* message);


int main(int argc, char* argv[]){
    int sock;
    char message[BUF_SIZE];
    int str_len, recv_len, recv_cnt;
    struct sockaddr_in serv_adr;

    if(argc!=3){
        printf("Useage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock=socket(PF_INET, SOCK_STREAM, 0);

    if(sock==-1)
        error_handling("socket() error");
    
    memset(&serv_adr, 0, sizeof(serv_adr));
    //serv_adr이라는 구조체에 소켓에 대한 정보를 때려박아준다.
    //여기서 IPv4를 이용한다고 지정한다
    serv_adr.sin_family=AF_INET;
    //Dotte-Decimal Notation 형식을 빅 엔디안 32비트 값으로 변환한다.
    //여기서 IP 주소를 문자열의 시작 주소를 넣어준다.
    serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
    //서버 포트 지정
    serv_adr.sin_port=htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
        error_handling("connect() error");
    
    else
        puts("Connect....");
    
    //여기부터가 앞선 코드의 문제를 해결하는 방법
    while(1){
        fputs("Input message(Q to quit: ", stdout);
        fgets(message,  BUF_SIZE, stdin);
        if(!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break;
        
        str_len=write(sock, message, strlen(message));

        recv_len=0;

        while(recv_len<str_len){
            recv_cnt=read(sock, &message[recv_len], BUF_SIZE-1);
            if(recv_cnt==-1)
                error_handling("read() error");
            recv_len+=recv_cnt;
        }
        message[recv_len]=0;
        printf("Message from server: %s", message);
    }
    close(sock);
    return 0;
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}