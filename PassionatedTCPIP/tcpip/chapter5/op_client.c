#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

//피연산자의 바이트 수와 연산결과의 바이트 수를 상수화했다.
#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4
void error_handling(char* message);

int main(int argc, char* argv[]){
    int sock;
    //데이터의 송수신을 위한 메모리 공간을 배열의 형태로 지정한다.
    //배열 형태로 메모리를 정의시 송수신시 누적이 가능해 편리하다.
    char opmsg[BUF_SIZE];
    int result, opnd_cnt, i;
    struct sockaddr_in serv_adr;

    if(argc!=3){
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    //소켓 초기화, IP protocol, TCP 방식을 이용한다.
    sock=socket(PF_INET, SOCK_STREAM, 0);
    if(sock==-1)
        error_handling("socket() error");
    
    //소켓 구조체의 초기화
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family=AF_INET;
    serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
    serv_adr.sin_port=htons(atoi(argv[2]));

    //
    if(connect(sock,(struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
        error_handling("connect() error");
    else
        puts("Connect....");

    fputs("Operand count: ", stdout);
    //데이터의 길이를 입력받아서 배열 0번으로 넣는다.
    scanf("%d", &opnd_cnt);
    opmsg[0]=(char)opnd_cnt;

    for(i=0; i<opnd_cnt; i++){
        printf("Operand %d: ", i+1);
        scanf("%d", (int*)&opmsg[i*OPSZ+1]);
    }
    //앞서 입력받은 정수들 뒤에 연산자 문자를 입력해야한다. 그를 위해 \n을 제거한다.
    fgetc(stdin);
    fputs("Operator: ", stdout);
    //실질적인 연산자 입력 부분
    scanf("%c", &opmsg[opnd_cnt*OPSZ+1]);
    //입력받은 내용들을 write함수를 이용해 한번에 전송한다.
    write(sock, opmsg, opnd_cnt*OPSZ+2);
    read(sock, &result, RLT_SIZE);

    printf("Operation result: %d \n", result);
    close(sock);
    return 0;
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}