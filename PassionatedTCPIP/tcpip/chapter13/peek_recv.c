#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define BUF_SIZE 30
void error_handling(char* message);

int main(int argc, char* argv[]){
    int acpt_sock, recv_sock;
    struct sockaddr_in acpt_adr, recv_adr;
    socklen_t recv_adr_sz;
    int str_len, state;
    char buf[BUF_SIZE];
    
    if(argc!=2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    acpt_sock=socket(PF_INET, SOCK_STREAM, 0);
    memset(&acpt_adr, 0, sizeof(acpt_adr));
    acpt_adr.sin_family=AF_INET;
    acpt_adr.sin_addr.s_addr=htonl(INADDR_ANY);
    acpt_adr.sin_port=htons(atoi(argv[1]));

    if(bind(acpt_sock, (struct sockaddr*)&acpt_adr, sizeof(acpt_adr))==-1)
        error_handling("bind() error");
    listen(acpt_sock, 5);

    recv_adr_sz=sizeof(recv_adr);
    recv_sock = accept(acpt_sock, (struct sockaddr*)&recv_adr, &recv_adr_sz);

    while(1){
        str_len = recv(recv_sock, buf, sizeof(buf)-1, MSG_PEEK|MSG_DONTWAIT);
        //recv 함수를 호출하면서 MSG_PEEK 옵션을 제공하고 있다.
        //MSG_DONTWAIT옵션을 같이 주는 이유는 데이터가 존재하지 않아 블로킹 상태에 빠지지 않도록 해야한다.
        if(str_len>0)
            break;
    }

    buf[str_len]=0;
    printf("Buffering %d bytes: %s \n", str_len, buf);
    
    str_len=recv(recv_sock, buf, sizeof(buf)-1, 0);
    //recv 함수를 한번 더 호출하여 아무 옵션도 설정하지 않음 -> 따라서 이번에 읽어들인 데이터는 입력버퍼에서 지워진다.
    buf[str_len]=0;
    printf("Read Again: %s \n", buf);
    close(acpt_sock);
    close(recv_sock);
    return 0;
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}