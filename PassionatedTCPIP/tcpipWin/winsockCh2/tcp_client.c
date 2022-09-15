#pragma comment(lib, "ws2_32.lib")
#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>
void ErrorHandling(char* message);

int main(int argc, char* argv[]) {
	WSADATA wsaData;
	SOCKET hSocket;
	//socket 함수의 반환 값 저장을 위해 선언하는 SOCKET 형 변수
	SOCKADDR_IN servAddr;

	char message[30];
	int strLen = 0;
	int idx = 0, readLen = 0;

	if (argc != 3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("hSocket() error");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		ErrorHandling("hSocket() error");

	memset(&hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = htons(atoi(argv[2]));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("connect() error");

	while (readLen = recv(hSocket, &message[idx++], 1, 0)) {
		//여기서 recv 호출을 통해서 1바이트씩 데이터를 읽는다
		if (readLen == -1)
			ErrorHandling("read() error");

		strLen += readLen;
	}
	printf("Message from server: %s \n", message);
	printf("Function read call count: %d \n", strLen);
	
	closesocket(hSocket);
	WSACleanup();
	return 0;
}

void ErrorHandling(char* message) {
	fputs(message, stdout);
	fputc('\n', stderr);
	exit(1);
}