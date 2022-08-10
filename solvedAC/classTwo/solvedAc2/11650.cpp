#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	int n;
	pair<int, int> point;
	vector<pair<int, int>> points;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> point.first >> point.second;
		points.push_back(make_pair(point.first, point.second));
	}

	sort(points.begin(), points.end());
	for (int i = 0; i < n; i++) {
		cout << points[i].first << " " << points[i].second << '\n';
	}
	return 0;
}