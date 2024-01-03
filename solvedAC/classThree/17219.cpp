#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);

	int n, m;
	string url, password;
	unordered_map<string, string> um;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> url;
		cin >> password;
		um[url] = password;
	}

	for (int i = 0; i < m; i++) {
		cin >> url;
		cout << um[url] << '\n';
	}
}