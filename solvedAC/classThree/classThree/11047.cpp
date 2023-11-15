#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, input, cnt = 0;
	vector<int> v;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());
	while (true) {
		if (k <= 0)
			break;

		if (v.back() > k) {
			v.pop_back();
		}

		else {
			k = k - v.back();
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}