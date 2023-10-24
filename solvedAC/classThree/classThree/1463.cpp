#include <iostream>
using namespace std;

/*
	if - else 문의 함정
	최소값이란 점은 항상 답이 되는 자료구조는 vector등을 생각해야한다.
	바텀업
	- 배열을 선언하고 하나씩 채워나가는 방식
*/

void getRes(int n) {
	int cnt = 0;
	while (true) {
		if (n == 1)
			break;

		if (n % 3 == 0) {
			n /= 3;
			cnt++;
		}
		else if ((n - 1) % 3 == 0) {
			n--;
			cnt++;
		}
		else if (n % 2 == 0) {
			n /= 2;
			cnt++;
		}
		else {
			n--;
			cnt++;
		}
	}
	cout << cnt << '\n';
}

int main(void) {
	int n;
	//cout << 2 % 3 << '\n';
	cin >> n;
	getRes(n);
}