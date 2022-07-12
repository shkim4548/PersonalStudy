#include<iostream>
using namespace std;

int gcd(int big, int little);
int lcm(int gcd, int big, int little);

int main(void) {
	int big, little, _gcd, _lcm;
	cin >> big >> little;
	_gcd = gcd(big, little);
	_lcm = lcm(_gcd, big, little);
	cout << _gcd << "\n" << _lcm;
}

int gcd(int big, int little) {
	while (little > 0) {
		int tmp = big;
		big = little;
		little = tmp % little;
	}
	return big;
}

int lcm(int gcd, int big, int little) {
	return (big * little) / gcd;
}