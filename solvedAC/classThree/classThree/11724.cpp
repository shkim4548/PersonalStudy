#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
vector<int> graph[MAX];
bool visited[MAX];
int cnt = 0;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	cnt++;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		//cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main(void) {
	int N, M, u, v;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			bfs(i);
		}
	}
	cout << cnt << '\n';
}