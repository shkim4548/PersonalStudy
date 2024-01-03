#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
const int MAX = 101;
vector<int> graph[MAX];
bool visited[MAX];

void bfs(int start) {
	int cnt = 0;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs(1);
}