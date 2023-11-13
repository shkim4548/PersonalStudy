#include <iostream>
#include <queue>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N, M;
int cnt = 0;

const int MAX = 101;
int graph[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int dist[MAX][MAX];

// 너비 우선 탐색으로 진행한다
void BFS(int yStart, int xStart) {
	queue<pair<int, int>> q;
	q.push(make_pair(yStart, xStart));
	dist[yStart][xStart]++;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 가동범위인지를 체크한다.
			if (ny < 0 || ny >= N || ny < 0 || ny >= M)
				continue;
			if (graph[ny][nx] == 0)
				continue;

			if (graph[ny][nx] == 1 && visited[ny][nx] == 0) {
				dist[ny][nx] = dist[y][x] + 1;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	int res = 0;
	string input;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) 
		{
			graph[i][j] = input[j] - '0';
		}
	}

	BFS(0, 0);
	cout << dist[N-1][M-1] << '\n';
	return 0;
}