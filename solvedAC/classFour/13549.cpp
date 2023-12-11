#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 100001;
bool visited[MAX];
int graph[MAX];
int n, k;

/*
	다익스트라 알고리즘
	- 대체 왜 이게 다익스트라 알고리즘이죠?
*/

int bfs(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, start));
	visited[start] = true;
	while (!q.empty())
	{
		int x = q.top().second;
		int cnt = q.top().first;
		q.pop();

		if (x == k)
			return cnt;

		// 노드를 옮겨 갈 때마다 cnt를 증가시킨다, cnt는 노드에 종속.
		if (x * 2 < MAX && visited[x * 2] == false)
		{
			q.push(make_pair(cnt, x * 2));
			visited[x * 2] = true;
			graph[x * 2] = cnt;
		}
		if (x + 1 < MAX && visited[x + 1] == false)
		{
			q.push(make_pair(cnt + 1, x + 1));
			visited[x + 1] = true;
			graph[x + 1] = cnt + 1;
		}
		if (x - 1 >= 0 && visited[x - 1] == false)
		{
			q.push(make_pair(cnt + 1,x - 1));
			visited[x - 1] = true;
			graph[x - 1] = cnt + 1;
		}
	}
	return 0;
}

int main(void)
{
	cin >> n >> k;
	cout << bfs(n) << '\n';
	return 0;
}