#include<iostream>
using namespace std;

int main(void) {
	//모든 방향으로 계차수열 6씩 차이난다.
	int n, an = 6, sum = 0, i;
	cin >> n;
	for (i = 1; i <= 100000000; i++) {
		if (n == 1) {
			cout << 1 << '\n';
			break;
		}
		if (sum >= n) {
			cout << i << '\n';
			break;
		}
		sum += an * i;
	}
	return 0;
}