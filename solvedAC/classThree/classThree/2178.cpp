#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N, M;
int cnt = 0;

const int MAX = 101;
int graph[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };

// 너비 우선 탐색으로 진행한다
void BFS(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 배열의 인덱스가 넘지 않도록 한다
		if (ny<0 || ny>N || nx<0 || nx>N)
			continue;

		queue<pair<int, int>> q;
		q.push(make_pair(ny, nx));
		visited[ny][nx]++;
		while (!q.empty()) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			cnt++;

			for (int j = 0; j < N; j++) {

			}
		}
	}
}

int main() {
	int res = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		graph[y][x] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] && !visited[i][j]) {
				res++;
				visited[i][j]++;
				BFS(i, j);
			}
		}
	}
	cout << res << '\n';
	return 0;
}