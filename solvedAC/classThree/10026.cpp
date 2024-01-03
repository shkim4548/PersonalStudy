#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 101;
char graph[MAX][MAX];
bool visited[MAX][MAX] = { false };
int N;
int cnt = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// 주변 탐색을 위주로 실행한다.
void dfs(int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) 
			continue;

		if (!visited[nx][ny] && graph[x][y] == graph[nx][ny])
		{
			dfs(nx, ny);
		}
	}
}

int main(void) {
	string input;
	cin >> N;

	// 그래프를 입력받는다.
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			graph[i][j] = input[j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << ' ';
	fill(visited[0], visited[0] + sizeof(visited) / sizeof(visited[0][0]), false);
	cnt = 0;

	// 적록색맹 그래프 작성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 'G')
				graph[i][j] = 'R';

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt <<'\n';
	return 0;
}