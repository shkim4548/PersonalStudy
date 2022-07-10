#include<iostream>
#include<vector>
using namespace std;

int main(void) {/*/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, input, tmp;
	int numbers[10000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (numbers[i] > numbers[j]) {
				tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << numbers[i] << '\n';
	}
	*/


	return 0;
}