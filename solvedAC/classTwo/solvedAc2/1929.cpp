#include<iostream>
//#include<vector>
using namespace std;

int main(void) {
	int start, end;
	int numbers[1000] = { 0 };
	cin >> start;
	cin >> end;
	for (int i = start; i <= end; i++) {
		if (numbers[i] == 0)
			continue;
		for (int j = 2 * i; i <= end; i++)
			numbers[j] = 0;
	}
	for (int i = 2; i <= end; i++) {
		if (numbers[i] != 0)
			cout << numbers[i] << '\n';
	}
	return 0;
}