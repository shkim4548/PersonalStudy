#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
	다익스트라 알고리즘
	- BFS에 우선순위 큐를 사용하여 누적치를 갱신한다
	- 이를 통해 가중치가 최소치인 경로를 찾아간다.
*/

const int INF = 100000000;
const int MAX = 1001;
vector<pair<int, int>> nodes[MAX];
int dist[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));	// dist를 짧은 거리 기준으로 정렬하기 위해 파라미터를 0을 앞에 배치, 앞에가 정렬기준
	while (!pq.empty())
	{
		// 우선순위큐는 내림차순 정렬이다
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		// 이미 최단거리 정보가 있다면 생략한다
		if (dist[here] < cost)
			continue;

		for (int i = 0; i < nodes[here].size(); i++)
		{
			int viaCost = cost + nodes[here][i].first;

			// here을 경유해서 가는게 빠르면 dist 갱신 후 push
			if (viaCost < dist[nodes[here][i].second])
			{
				dist[nodes[here][i].second] = viaCost;
				// 내림차순 정렬을 위해 음수를 사용
				pq.push({ viaCost, nodes[here][i].second });
			}
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	// 초기화, 모든 거리를 우선 INF로 하여 이동을 불가하게 한다.
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}

	// 그래프를 입력받아 노드를 채운다.
	for (int i = 1; i <= m; i++) 
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		nodes[start].push_back(make_pair(cost, end));
	}
	int startPoint, endPoint;
	cin >> startPoint >> endPoint;
	// end를 넣을 필요는 없는게 전체 순회 후 최소 비용을 구한다 -> 마지막에 dist[endPoint];
	dijkstra(startPoint);
	cout << dist[endPoint] << '\n';
}