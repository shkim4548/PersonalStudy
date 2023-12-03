#include<iostream>
#include<vector>
using namespace std;

const int MAX = 9;
int vec[MAX] = { 0, };
bool visited[MAX] = { 0, };
int n, m;

void dfs(int cnt, int index)
{
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << vec[i] << ' ';
		cout << '\n';
	}
	for (int i = index; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			vec[cnt] = i;
			dfs(cnt + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	dfs(0, 1);
}
