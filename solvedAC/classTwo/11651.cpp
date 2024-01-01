#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool customSort(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<pair<int, int>> v1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v1.push_back(make_pair(a, b));
	}

	sort(v1.begin(), v1.end(), customSort);

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i].first <<" "<< v1[i].second << '\n';
	}
}