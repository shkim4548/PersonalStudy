#pragma comment(lib, "ws2_32.lib")
#include<stdio.h>
#include<winsock2.h>

int main(int argc, char* argv[]) {
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2,2), &wsaData))
}