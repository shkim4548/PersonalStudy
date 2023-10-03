#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	int m, n;
	queue<int> original;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		//cout << i << " ";
		original.push(i);
		//cout << original.back() << " ";
	}
	cout << "<";
	// 요세푸스 큐 구현
	while (original.size() > 1) {
		for (int i = 1; i < m; i++) {
			int temp = original.front();
			original.pop();
			original.push(temp);
		}
		cout << original.front() << ", ";
		original.pop();
	}
	cout << original.front() << ">" << '\n';
	return 0;
}