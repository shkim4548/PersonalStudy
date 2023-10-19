#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	좌상단을 기준으로 잡고 모두 찾아서 최소값을 찾는다.
*/

int main() {
	vector<vector<char>> chess;
	vector<int> res;
	int n, m;
	char input, leftup, rightdown;
	
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> input;
			chess[i].push_back(input);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << chess[i][j] << ' ';
		}
		cout << '\n';
	}
}