#include<iostream>
using namespace std;

void difference_sequence(int n) {
	int i, result = 1;
	for (i = 0; i <= n; i++) {
		if (result >= n) {
			cout << i << " ";
			break;
		}
		//cout << result << '\n';
		result += i + 6;
	}
}

int main(void) {
	int input;
	cin >> input;
	difference_sequence(input);
	return 0;
}