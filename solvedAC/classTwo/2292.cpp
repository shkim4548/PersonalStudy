#include<iostream>
using namespace std;

int main(void) {
	//��� �������� �������� 6�� ���̳���.
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