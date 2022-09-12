#pragma comment(lib, "ws2_32.lib")
#include<stdio.h>
#include<windows.h>
#include<process.h>
unsigned WINAPI ThreadFunc(void* arg);

int main(int argc, char* argv[]) {
	HANDLE hThread;
	unsigned threadID;
	int param = 5;

	hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadFunc, (void*)&param, 0, &threadID);
	//�������� main�Լ��� ThreadFunc�� �׸��� ThreadFunc�� ���� param�� ���� �����ϸ鼭 �������� ������ �䱸�Ѵ�.
	if (hThread == 0) {
		puts("_beginthreadex() error");
		return -1;
	}
	Sleep(3000);
	//Sleep �Լ��� 1/1000�� ������ ���ŷ ���¸� �����. 3�ʰ��� ���ð��� �����
	puts("end of main");
	return 0;
}

unsigned WINAPI ThreadFunc(void* arg) {
	//WINAPI��� ������ ������ Ű���尡 ���� ���δ�. �̴� �Ű������� ���� ������, �Ҵ�� ������ ��ȯ��� ����
	int i;
	int cnt = *((int*)arg);
	for (i = 0; i < cnt; i++) {
		Sleep(1000);
		puts("running thread");
	}
	return 0;
}