#include<iostream>
#include<math.h>
using namespace std;

int arr[1000001];

int main(void) {
	int cnt = 0, a, b;
	cin >> a >> b;
	for (int i = 2; i < b; i++) {
		arr[i] = i;
	}
	for (int i = 2; i < sqrt(b); i++) {
		if (arr[i] == 0)
			continue;
		for (int j = 2 * i; j <= b; j += i) {
			arr[j] = 0;
		}
	}
	for (int i = a; i <= b; i++) {
		if (arr[i] != 0)
			cout << arr[i] << '\n';
	}
}