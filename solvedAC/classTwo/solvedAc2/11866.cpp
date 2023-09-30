#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	int m, n, count = 0;
	queue<int> original;
	queue<int> temp;
	queue<int> result;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		//cout << i << " ";
		original.push(i);
		//cout << original.back() << " ";
	}
	int i = m;

	return 0;
}