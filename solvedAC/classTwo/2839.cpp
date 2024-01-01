#include <iostream>
using namespace std;

/*
	다이나믹 프로그래밍 + 그리디 알고리즘 = 최대화/최소화 계산을 수행한다.
*/

int main(void) {
	int n, count = 0;
	cin >> n;

	while (n >= 0) {
		if (n % 5 == 0) {
			count += n / 5;
			cout << count << '\n';
			return 0;
		}
		n -= 3;
		count++;
	}

	cout << -1 << '\n';
	return 0;
}