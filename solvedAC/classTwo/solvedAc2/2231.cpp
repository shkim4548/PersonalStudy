#include<iostream>
using namespace std;

int main(void) {
	int n, m, hund, ten, one;
	cin >> n;

	hund = n / 100;
	//cout << hund << '\n';
	ten = (n % 100 - n % 10) / 10;
	//cout << ten << '\n';
	one = n % 10;
	//cout << one << '\n';

	cout << n - (hund + ten + one);
	return 0;
}