#include <iostream>
#include <vector>
using namespace std;

/*
	누적합
	배열의 [A ~ B] 범위의 구간합을 구하고자 할 때, 누적합 배열을 구한 후
	B까지의 누적합에서 A~B 범위의 구간의 합을 구할 수 있다.
*/

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, from, to, sum = 0;
	cin >> n >> m;
	vector<int> vec(n);
	vector<int> res(m);

	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
		res[i] = res[i - 1] + vec[i];
	}

	// 누적합 알고리즘
	while (m--) {
		cin >> from >> to;
		cout << res[to] - res[from - 1] << '\n';
	}

	return 0;
}