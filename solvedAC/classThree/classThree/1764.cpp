#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, cnt = 0;
	string input;
	unordered_map<string, string> listen;
	vector<string> res;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> input;
		listen.insert(make_pair(input, input));
	}

	for (int j = 0; j < m; j++) {
		cin >> input;
		if (listen[input] != "") {
			res.push_back(input);
			cnt++;
		}
	}

	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}

	return 0;
}