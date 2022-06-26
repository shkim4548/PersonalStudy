#include<iostream>
#include<math.h>
using namespace std;

int factorial(int a);

int main(void) {
	int n, k;
	cin >> n;
	cin >> k;

	if (k < 0) {
		//cout << "k<0" << endl;
		cout << 0 << endl;
	}
	else if (k >= 0 && k <= n) {
		cout << factorial(n) / (factorial(k) * factorial(n - k)) << endl;
	}
	else if (k >= n) {
		//cout << "k>n" << endl;
		cout << 0 << endl;
	}
}

int factorial(int a) {
	int result = 1;
	for (int i = 1; i <= a; ++i) {
		result = result * i;
	}
	return result;
}