#include<iostream>
using namespace std;

int main(void) {
	int n, m, nums, card[100] = { 0, }, sum, max = 0;
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++) {
		cin >> nums;
		card[i] = nums;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; j < n; j++) {
				sum = card[i] + card[j] + card[k];
				if (sum <= m && sum > max) {
					max = sum;
				}
			}
		}
	}
	//cout << '\n' << max;
	cout << max;
	return 0;
}