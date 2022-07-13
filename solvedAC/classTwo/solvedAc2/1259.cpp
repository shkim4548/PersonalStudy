#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string n;
	bool ans;
	char input;
	for (int i = 0; i < 100; i++) {
		cin >> input;
		n.push_back(input);
		//예외처리
		//0 입력시 종료
		if (input == '0') return;
		//첫자리가 0인 경우 제외
		else if (n[0] == '0') return;
		//당연히 짝수면 펠린드롬수 일 수 없음
		else if (n.size() % 2 == 0) ans = false;
	}
	return 0;
}