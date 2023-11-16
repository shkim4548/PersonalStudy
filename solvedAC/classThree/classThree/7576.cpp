#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
	도마도 문제
	- 시작점이 0, 0이 아닌 경우
	- 시작점이 여러개인 경우
*/

const int MAX = 1001;
//vector<vector<int>> graph(MAX);
int graph[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int dist[MAX][MAX] = { 0 };
queue<pair<int, int>> q;
int N, M, sum = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs()
{
	// 출발점이 여러개이므로 지역변수로 사용한다.
	//q.push(make_pair(xStart, yStart));
	//dist[xStart][yStart]++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				continue;
			}

			if (graph[nx][ny] == 0 && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				graph[nx][ny] = graph[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> xStarts, yStarts;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// bfs를 모두 작동시켰음에도 0이 존재한다.
			if (graph[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}

			// 그게 아니라면 얼마나 걸렸는가
			if (sum < graph[i][j])
				sum = graph[i][j];
		}
	}
	cout << sum - 1 << '\n';
	return 0;
}