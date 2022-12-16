#include<iostream>
#include<math.h>
using namespace std;

int arr[1000001];

int main(void) {
	/*
	int a, b, cnt = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		cnt = 0;
		for (int j = 2; j <= i; j++) {
			if (i % j == 0)
				cnt++;
		}
		if (cnt == 1)
			cout << i << '\n';
	}
	return 0;
	*/
	//이상 2중 for문 풀이

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