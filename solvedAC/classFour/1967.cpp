#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10001;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
int dist[MAX];
int endPoint = 0, ans = 0;

/*
	트리의 지름
	- 가중치가 있으므로 pair로 각 노드를 지정해줘야한다.

	가중치가 있는 dfs
	- 파라미터로 cost를 따로 받아준다.
	- cost가 큰 것은 생략하여 속도를 확보한다
*/

void dfs(int x, int cost)
{
	if (visited[x])
		return;

	visited[x] = true;
	if (ans < cost)
	{
		ans = cost;
		endPoint = x;
	}

	for (int i = 0; i < graph[x].size(); i++)
	{
		dfs(graph[x][i].first, cost + graph[x][i].second);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int start, end, cost;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> start >> end >> cost;
		graph[start].push_back(make_pair(end, cost));
		graph[end].push_back(make_pair(start, cost));
	}

	// 가장 멀리 있는 정점
	dfs(1, 0);

	// dfs를 다시 실행하기 위해서 초기화한다.
	ans = 0;
	memset(visited, 0, sizeof(visited));

	// endPoint와 가장 멀리 있는 정점과 거리 구하기
	dfs(endPoint, 0);
	cout << ans << '\n';

	return 0;
}