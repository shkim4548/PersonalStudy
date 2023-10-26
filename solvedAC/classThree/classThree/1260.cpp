#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

/*
	memset GNU 컴파일러에선 cstring을 무조건 포함해야한다
*/

const int MAX = 1001;
vector<int> graph[MAX];
bool visited[MAX];

void DFS(int x) {
	visited[x] = true;
	cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y])
			DFS(y);
	}
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, v;
	cin >> n >> m >> v;

	// 그래프의 인접리스트를 작성한다 C스타일로 하면 인접행렬이 유리하다
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		// 무방향 그래프(양방향 연결)
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// 문제에서 요구한 출력에 맞추기 위해 정렬한다
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(v);

	cout << '\n';
	memset(visited, 0, n + 1);
	
	BFS(v);
	return 0;
}