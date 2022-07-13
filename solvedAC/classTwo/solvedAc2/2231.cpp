#include<iostream>
using namespace std;

int main(void) {
	int n, m, compare[27] = { 0, }, divide;
	cin >> n;
	
	for (int i = 1; i <= 27; i++) {
		compare[i] = n - i;
	}

	return 0;
}