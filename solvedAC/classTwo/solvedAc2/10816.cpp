#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*-----------------------
	unoredered_map
	unordered_map과 딕셔너리의 차이를 알아보자
-------------------------*/

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, input;
	unordered_map<int, int> map;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		map[input]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		cout << map[input] << ' ';
	}

	return 0;
}