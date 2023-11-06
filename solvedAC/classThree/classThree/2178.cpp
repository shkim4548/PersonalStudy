#include <iostream>
#include <vector>
#include <queue>

/*
	미로찾기 문제
	- 유기농 배추문제의 BFS 버전이라고 봐도 좋다
	- 인접행렬을 이용하여 푼다.
*/

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0,0,1, -1 };
int N;
const int MAX = 101;
int graph[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { 0 };

// 너비 우선 탐색을 처리
void BFS(int y, int x) {
	// 주위를 둘러보며 처리한다

	std::queue<int> q;
	q.push(x);
	visited[x][y] = true;
	while (!q.empty()) {
		int tx = q.front();
		q.pop();

		for (int i = 0; i < N; i++) {
			int ty = graph[tx][i];
			if(!visited[u])
		}
	}
}


int main(void) {
	int n, m;
	std::cin >> n >> m;

	// 일단 그래프를 입력받는다.
	for (int i = 0; i < n; i++) {

	}
}