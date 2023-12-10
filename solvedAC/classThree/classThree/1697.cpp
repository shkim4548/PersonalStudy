#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10000001;
int graph[MAX];
bool visited[MAX] = { false, };
int dist[MAX];
int n, k;

/*
	1차원 너비 우선 탐색
	- 이동 방향은 +, - 단 두개이다.
	- cnt++로 if로 하나씩 처리하면 그냥 찔러본 구간도 전부 세버린다.
	- cnt를 queue에 넣어야 순회를 하면서 마지막 정점에서 return한다.
*/

int bfs(int start)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	visited[start] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == k)
			return cnt;

		// 노드를 옮겨 갈 때마다 cnt를 증가시킨다.
		else if (x + 1 < MAX && visited[x + 1] == false)
		{
			q.push(make_pair(x + 1, cnt + 1));
			visited[x + 1] = true;
		}
		if (x - 1 >= 0 && visited[x - 1] == false)
		{
			q.push(make_pair(x - 1, cnt + 1));
			visited[x - 1] = true;
		}
		if (x * 2 < MAX && visited[x * 2] == false)
		{
			q.push(make_pair(x * 2, cnt + 1));
			visited[x * 2] = true;
		}
	}
	return 0;
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	graph[k] = 1;
	cout << bfs(n) << '\n';
	return 0;
}