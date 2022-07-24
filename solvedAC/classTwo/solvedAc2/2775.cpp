#include<iostream>
using namespace std;

int difference_sequence(int n) {
	int an = 6, sum = 0;
	while (1) {
		int i = 0;
		i++;
		if (n == i) {
			return i;
			break;
		}
		sum += an;
		an += i;
	}
}

int main(void) {
	int input;
	cin >> input;
	cout << difference_sequence(input);
	return 0;
}