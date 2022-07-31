#include<iostream>
#include<string>
#include<math.h>
using namespace std;

//123456789보다 크면 123456789로 나눈 나머지를 구해야한다.
int main(void) {
	int n, hash = 31;
	long long hashed = 0;
	char input[50];
	//입력은 영문 소문자만, ASCII 'a'==97
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < n; i++) {
		//사칙 연산 에서 곱셈은 덧셈보다 우선됩니다. 잊지 맙시다 괄호치기
		hashed += ((int)input[i] - 96) * (int)pow(hash, i);
		//cout << (int)input[i] - 96 << " ";
		//cout << (int)pow(hash, i) << " " << i;
		//cout << hashed << '\n';
	}
	cout << hashed;
}