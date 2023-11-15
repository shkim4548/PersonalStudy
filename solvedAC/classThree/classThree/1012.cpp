#include <iostream>
#include <cstring>
using namespace std;

/*
	유기농 배추 문제
	- 인접 행렬로 풀어본다.
	- 이전까지는 전부 인접리스트를 작성했었다.
*/

// 그래프 4방으로 이동하기 위한 연산자 역할의 배열
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N, M, K;
const int MAX = 51;
int graph[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };

// 상하 좌우 하나씩 이동하며 해당 지점들에 대해서 DFS를 각각 실행한다.
void DFS(int y, int x) {
	// 그래프 4방을 탐색하는 내용
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 배열의 인덱스를 넘지 않도록 체크한다
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		// 방문 하지 않았으며 배추가 있다면 탐색을 계속한다.
		if (graph[ny][nx] && !visited[ny][nx]) {
			visited[ny][nx]++;	// bool이니까 true가 되겠죠?
			DFS(ny, nx);
		}
	}
	
}

int main(void) {
	int x, y, T;
	cin >> T;

	for (int test = 0; test < T; test++) {
		cin >> M >> N >> K;

		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));
		int res = 0;

		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			graph[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] && !visited[i][j]) {
					res++;
					visited[i][j]++;
					DFS(i, j);
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}