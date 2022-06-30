#include<iostream>
using namespace std;

int main(void) {
	int a, b, c, powa = 0, powb = 0, powc = 0;
	for (int i = 0; i < 30000; i++) {
		cin >> a >> b >> c;
		powa = a * a;
		powb = b * b;
		powc = c * c;
		if (a == 0 && b == 0 && c == 0)
			return 0;
		else if (powa + powb == powc || powa + powc == powb || powb + powc == powa)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	return 0;
}