#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define BUF_SIZE 1024
#define OPSZ 4
void error_handling(char* message);
int calculate(int opnum, int opnds[], char operator);

int main(int argc, char* argv[]){
    int serv_sock, clnt_sock;
    char opinfo[BUF_SIZE];
    int result, opnd_cnt, i;
    int recv_cnt, recv_len;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    if(argc!=2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    //서버소켓 초기화
    serv_sock=socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock==-1)
        error_handling("socket() errer");
    
    //소켓 구조체 초기화
    memset(&serv_adr,0,sizeof(serv_adr));
    serv_adr.sin_family=AF_INET;
    serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_adr.sin_port=htons(atoi(argv[1]));
    
    //bind를 이용해 IP와 
    if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
        error_handling("bind() error");

    if(listen(serv_sock,5)==-1)
        error_handling("listen() error");
    clnt_adr_sz=sizeof(clnt_adr);
    //클라이언트가 발송한 데이터를 바이트 단위로 반복해서 읽는다.
    for(i=0;i<5;i++){
        opnd_cnt=0;
        clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        //제일먼저 연산자 갯수 정보를 읽는다.
        read(clnt_sock, &opnd_cnt, 1);

        recv_len=0;
        while((opnd_cnt*OPSZ+1)>recv_len){
            recv_cnt=read(clnt_sock, &opinfo[recv_len], BUF_SIZE-1);
            recv_len+=recv_cnt;
        }
        result=calculate(opnd_cnt, (int*)opinfo, opinfo[recv_len-1]);
        write(clnt_sock, (char*)&result, sizeof(result));
    }
    close(clnt_sock);
    return 0;
}

int calculate(int opnum, int opnds[], char op){
    int result=opnds[0], i;
    switch(op){
        case '+':
            for(i=1;i<opnum;i++)
                result+=opnds[i];
                break;
        case '-':
            for(i=1;i<opnum;i++)
                result-=opnds[i];
                break;
        case '*':
            for(i=0;i<opnum;i++)
                result*=opnds[i];
                break;
    }
    return result;
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}