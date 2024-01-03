#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M;
int cnt = 0;

const int MAX = 601;
int graph[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };
int dist[MAX][MAX];

void bfs(int yStart, int xStart)
{
	queue<pair<int, int>> q;
	q.push(make_pair(yStart, xStart));
	dist[yStart][xStart]++;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 가동범위인지를 체크한다.
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			// 가동 범위 내부이지만 갈 수 없는 부분을 체크한다.
			if (graph[ny][nx] == 'X')
				continue;

			if (visited[ny][nx] == true)
				continue;

			// 진짜 문제 풀이 지점
			if (graph[ny][nx] == 'P')
				cnt++;

			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int xs = 0, ys = 0, tx = 0, ty = 0;
	string input;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			// 한글자씩 분리하여 입력받는다.
			graph[i][j] = input[j];
			if (input[j] == 'I')
			{
				xs = i;
				ys = j;
			}
		}
	}

	bfs(xs, ys);
	if (cnt == 0)
		cout << "TT" << '\n';
	else
		cout << cnt << '\n';
	return 0;
}