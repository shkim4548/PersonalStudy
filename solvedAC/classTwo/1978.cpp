#include<iostream>

using namespace std;
/*
int primeNumber(int n) {
	if (n < 2) return 0;
	for (int i = 2; i < n; i++) {
		if (n & i == 0) {
			return 0;
		}
	}
	return 1;
}
*/
int main(void) {
	int n, input, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input < 2) continue;
		for (int j = 2; j < input; j++) {
			if (input % j == 0) {
				break;
			}
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}