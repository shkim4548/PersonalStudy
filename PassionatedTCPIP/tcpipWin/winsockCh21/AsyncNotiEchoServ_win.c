#pragma comment(lib, "ws_32.lib")
#include<stdio.h>
#include<string.h>
#include<winsock2.h>

#define BUF_SIZE 100

void CompressSockets(SOCKET hSockArr[], int idx, int total);
void CompressEvent(WSAEVENT hEventArr[], int idx, int total);
void ErrorHandling(char* message);

int main(int argc, char* argv[]) {
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAdr, clntAdr;

	SOCKET hSockArr[WSA_MAXIMUM_WAIT_EVENTS];
	WSAEVENT hEventArr[WSA_MAXIMUM_WAIT_EVENTS];
	WSAEVENT newEvent;
	WSANETWORKEVENTS netEvents;

	int numOfClntSock = 0;
	int strLen, i;
	int posInfo, startIdx;
	int clntAdrLen;
	char msg[BUF_SIZE];

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");
	//이상 일반적인 선언문 및 초기화 모음

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[0]));

	if(bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr))==SOCKET_ERROR)
		ErrorHandling("bind() error");

	if(listen(hServSock, 5)==SOCKET_ERROR)
		ErrorHandling("listen() error");

	newEvent = WSACreateEvent();
	if (WSAEventSelect(hServSock, newEvent, FD_ACCEPT) == SOCKET_ERROR)
		ErrorHandling("WSAEvnetSelect() error");

	hSockArr[numOfClntSock] = hServSock;
	hEventArr[numOfClntSock] = newEvent;
	numOfClntSock++;
	//이상 소켓 초기화 및 WSAEventSelect 함수호출을 통해 연결되는 소켓과 Event 오브젝트의 핸들정보를 각각 hSockArr과 hEvnetArr에 저장하는 코드이다.

	while (1) {
		posInfo = WSAWaitForMultipleEvents(numOfClntSock, hEventArr, FALSE, WSA_INFINITE, FALSE);
		startIdx = posInfo - WSA_WAIT_EVENT_0;
		
		for (i = startIdx; i < numOfClntSock; i++) {
			int sigEventIdx = WSAWaitForMultipleEvents(1, &hEventArr[i], TRUE, 0, FALSE);
			if ((sigEventIdx == WSA_WAIT_FAILED || sigEventIdx == WSA_WAIT_TIMEOUT)) { //연결 요청시
				continue;
			}
			else {
				if (netEvents.lNetworkEvents & FD_ACCEPT) {
					sigEventIdx = 1;
					WSAEnumNetworkEvents(hSockArr[sigEventIdx], hEventArr[sigEventIdx], &netEvents);
					if (netEvents.iErrorCode[FD_ACCEPT_BIT] != 0) {
						puts("Accept Error");
						break;
					}
					clntAdrLen = sizeof(clntAdr);
					hClntSock = accept(hSockArr[sigEventIdx], (SOCKADDR*)&clntAdr, &clntAdrLen);
					WSAEventSelect(hClntSock, newEvent, FD_READ | FD_CLOSE);
					hEventArr[numOfClntSock] = newEvent;
					hSockArr[numOfClntSock] = hClntSock;
					numOfClntSock++;
					puts("connected new client");
				}
			
			if (netEvents.lNetworkEvents & FD_READ) {
				if (netEvents.iErrorCode[FD_READ_BIT]) {
					puts("Read Error");
					break;
				}
				strLen = recv(hSockArr[sigEventIdx], msg, sizeof(msg), 0);
				send(hSockArr[sigEventIdx], msg, strLen, 0);
			}
			if (netEvents.lNetworkEvents & FD_CLOSE) {//종료 요청시
				if (netEvents.iErrorCode[FD_CLOSE_BIT] != 0) {
					puts("Close Error");
					break;
				}
				WSACloseEvent(hEventArr[sigEventIdx]);
				closesocket(hSockArr[sigEventIdx]);

				numOfClntSock--;
				CompressSockets(hSockArr, sigEventIdx, numOfClntSock);
				CompressSockets(hEventArr, sigEventIdx, numOfClntSock);
			}
			}		
		}
	}
	WSACleanup();
	return 0;
}

void CompressSocket(SOCKET hSocketArr[], int idx, int total) {
	int i;
	for (i = idx; i < total; i++)
		hSocketArr[i] = hSocketArr[i + 1];
}

void CompressEvent(WSAEVENT hEventArr[], int idx, int total) {
	int i;
	for (i = idx; i < total; i++)
		hEventArr[i] = hEventArr[i + 1];
}

void ErrorHandlint(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}