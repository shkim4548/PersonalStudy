#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*-------------
	이진탐색
---------------*/

int main(void) {
	int n, input, m;
	vector<int> v1;
	vector<int> v2;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v1.push_back(input);
	}

	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> input;
		v2.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v1[i] == v2[j]) {
				cout << v1[i] << " " << v2[j] << '\n';
				continue;
			}
		}
		cout << 0 << '\n';
	}
}