#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>

void ErrorHandling(char* message);

int main(int argc, char* argv[]){
    WSADATA wsaData;
    SOCKET hServSock, hClntSock;
    SOCKADDR_IN servAddr, clntAddr;

    int szClntAddr;

    char message[] ="HelloWorld";
    if(argc!=2){
        printf("Useage : %s <port>\n", argv[0]);
        exit(1);
    }

    if(WSAStartup(MAKEWORD(2,2), &wsaData)!=0)
        ErrorHandling("WSAStartup() error!");
        //소켓 라이브러리를 초기화하고 있다.

    hServSock=socket(PF_INET, SOCK_STREAM, 0);
        //소켓을 생성하고 IP주소와 PORT번호를 할당하고 있다.
    if(hServSock==INVALID_SOCKET)
        ErrorHandling("bind() error");

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family=AF_INET;
    servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servAddr.sin_port=htons(atoi(argv[1]));

    if(bind(hServSock, (SOCKADDR*) &servAddr, sizeof(servAddr))==SOCKET_ERROR)
        ErrorHandling("bind() error");

    if(listen(hServSock, 5)==SOCKET_ERROR)
        ErrorHandling("listen() error");
    
    szClntAddr=sizeof(clntAddr);
    hClntSock=accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
    if(hClntSock == INVALID_SOCKET)
        ErrorHandling("accept() error");

    send(hClntSock, message, sizeof(message),0);
    //send 함수 호출을 통해서 accept
    closesocket(hClntSock);
    closesocket(hServSock);
    WSACleanup();
    //종료전 소켓 라이브러리 해제
    return 0;
}

void ErrorHandling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
/*
    memset(void* ptr, int value, size_t num) 함수
    메모리를 특정 값으로 세팅하는 함수
    ptr : 세팅하고자 하는 메모리의 시작 주소, 포인터의 위치
    value : 메모리에 할당하고자 하는 실질적 데이터, int이지만 저장시 unsigned char로 저장된다
    num : 길이, 바이트 단위
*/