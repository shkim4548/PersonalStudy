#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

const int MAX = 1001;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX] = { 0 };
int N, M;

void bfs(int yStart, int xStart) {
	// 2차원 벡터 및 BFS를 위한 초기화
	queue<pair<int, int>> q;
	q.push(make_pair(yStart, xStart));
	//dist[yStart][xStart] += 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) 
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= M || nx < 0 || nx >= M)
				continue;
			if (graph[ny][nx] == 0)
				continue;

			if (graph[ny][nx] == 1 && visited[ny][nx] == 0) 
			{
				dist[ny][nx] = dist[y][x] + 1;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	int input, iStart, jStart;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			graph[i][j] = input;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 2) {
				iStart = i;
				jStart = j;
			}
		}
	}
	bfs(iStart, jStart);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 원래 갈 수 있지만 지나가지 않는 경우
			if (graph[i][j] == 1 && dist[i][j] == 0) {
				cout << -1 << ' ';
			}
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}