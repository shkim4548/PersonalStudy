#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int>& v, int key) {
	int low = 0;
	int high = v.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == v[mid])
			return true;

		else if (key < v[mid])
			high = mid - 1;
		else if (key > v[mid])
			low = mid + 1;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, input;
	vector<int> standard, compare, res;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		standard.push_back(input);
	}

	for (int i = 0; i < n; i++)
		cout << standard[i] << '\n';

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		compare.push_back(input);
	}

	sort(standard.begin(), standard.end());
}