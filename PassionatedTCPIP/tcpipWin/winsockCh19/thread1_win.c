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
	//쓰레드의 main함수로 ThreadFunc를 그리고 ThreadFunc에 변수 param의 값을 전달하면서 쓰레드이 생성을 요구한다.
	if (hThread == 0) {
		puts("_beginthreadex() error");
		return -1;
	}
	Sleep(3000);
	//Sleep 함수는 1/1000초 단위로 블로킹 상태를 만든다. 3초간의 대기시간을 만든다
	puts("end of main");
	return 0;
}

unsigned WINAPI ThreadFunc(void* arg) {
	//WINAPI라는 윈도우 고유의 키워드가 눈에 보인다. 이는 매개변수의 전달 방향의, 할당된 스택의 반환방법 등을
	int i;
	int cnt = *((int*)arg);
	for (i = 0; i < cnt; i++) {
		Sleep(1000);
		puts("running thread");
	}
	return 0;
}