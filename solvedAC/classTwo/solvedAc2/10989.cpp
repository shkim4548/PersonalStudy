#include<iostream>
using namespace std;

//#define arrSize 1000000000

//스택 40020 바이트 경고 해결을 위해 전역변수로 선언(visual c++ 컴파일러 경고)
int cnt[10001] = { 0 };

int main(void) {
	//배열에 누적합을 사용한다.
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cnt[input]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}