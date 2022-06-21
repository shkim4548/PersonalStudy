#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char*message);

int main(int argc, char* argv[]){
    int serv_sock, clnt_sock;
    char message[BUF_SIZE];
    int str_len, i;

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    if(argc!=2){
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    //소켓 초기화 복습
    //PF_INET: Protocol Family INET, 
    //SOCK_STREAM: 스트림소켓 사용, TCP 프로토콜을 사용하겠다는 의미
    serv_sock=socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock==1){
        error_handling("socket() error");
    }
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family=AF_INET;
    serv_adr.sin_addr.s_addr==htonl(INADDR_ANY);
    serv_adr.sin_port=htons(atoi(argv[1]));
    
    //bind 실시, 여기서 소켓에 포트를 지정한다. 실패시 에러메시지를 반환 후 종료.
    if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
        error_handling("bind() error");
    
    //listen 실시, 클라이언트의 접속을 기다리며, 실패서 에러메시지를 반환 후 종료
    if(listen(serv_sock,5)==-1)
        error_handling("listne() error");
    
    clnt_adr_sz=sizeof(clnt_adr);

    for(i=0;i<5;i++){
        clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        if(clnt_sock==-1)
            error_handling("accept() error");
        else
            printf("Connected client %d \n", i+1);
        
        while((str_len=read(clnt_sock, message, BUF_SIZE))!=0)
            write(clnt_sock, message, str_len);
    }
        close(clnt_sock);
        return 0;
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}