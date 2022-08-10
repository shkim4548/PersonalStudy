#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool customSort(pair<int, int> param1, pair<int, int> param2) {
	if (param1.second < param2.second) {
		return param1.second < param2.second;
	}
	else {
		return param1.first < param2.second;
	}
}

int main(void) {
	int n;
	pair<int, int> point;
	vector<pair<int, int>> points;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> point.first >> point.second;
		points.push_back(make_pair(point.first, point.second));
	}

	sort(points.begin(), points.end(), customSort);
	//sort(points.begin(), points.end(), customSortX);

	for (int i = 0; i < n; i++) {
		cout << points[i].first << " " << points[i].second << '\n';
	}
	return 0;
}