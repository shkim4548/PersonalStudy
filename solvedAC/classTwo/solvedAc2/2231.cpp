#include<iostream>
using namespace std;

int main(void) {
	int n, num = 0, result = 0, sum = 0, cnt = 0;
	cin >> n;
	num = n;

	while (num > 0) {
		num /= 10;
		++cnt;
	}

	//cout << n << '\n';
	for (int i = n - (cnt * 9); i < n; i++) {
		num = i;
		sum = i;
		//cout << num << " " << sum;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
			//cout << sum << '\n';				
		}
		if (n == sum) {
			result = i;
			break;
		}
	}
	cout << result;
	return 0;
}