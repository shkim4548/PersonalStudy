#include<stdio.h>
#include<windows.h>
#include<process.h>

#define NUM_THREAD 50
unsigned WINAPI threadInc(void* arg);
unsigned WINAPI threadDes(void* arg);

long long num = 0;
CRITICAL_SECTION cs;
//CRITICAL_SECTION 기반 동기화

int main(int argc, char* argv[]) {
	HANDLE tHandles[NUM_THREAD];
	int i;

	InitializeCriticalSection(&cs);
	for (i = 0; i < NUM_THREAD; i++) {
		if (i % 2)
			tHandles[i] = (HANDLE)_beginthreadex(NULL, 0, threadInc, NULL, 0, NULL);
		else
			tHandles[i]=(HANDLE)_beginthreadex(NULL, 0, )
	}
}