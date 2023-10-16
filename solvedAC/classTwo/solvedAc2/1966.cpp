#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m, index, input;
	vector<vector<pair<int, int>>> vp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m >> index;
		for (int j = 0; j < m; j++) {
			cin >> input;
			vp[j].push_back(make_pair(input, j + 1));
		}
		cout << i << '\n';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < vp[i].size(); j++) {
			cout << vp[i][j].first << " " << vp[i][j].second << ', ';
		}
		cout << '\n';
	}
}