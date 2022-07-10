#include<iostream>
using namespace std;

int main(void) {
	int n, hund, ten, one;
	cin >> n;

	hund = n / 100;
	ten = (n % 100) / 10;
	one = n % 10;

	cout << n + hund + ten + one;
	return 0;
}