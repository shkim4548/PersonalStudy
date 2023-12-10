#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
	다익스트라 알고리즘
	- BFS에 우선순위 큐를 사용하자
	- 이번엔 출발점이 여러개
	- 순회 알고리즘과 DIST배열의 특징상 굳이 여러번 예외 처리를 할 필요는 없다.
	- 문제의 조건에 맞춰서 시작점은 0으로 강제 초기화, 루프가 허용되면 불가능한 풀이
*/

const int INF = 10000000;
const int MAX = 20001;
vector<pair<int, int>> nodes[MAX];
int dist[MAX];

void Dijkstara(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		// 이미 최단거리 정보가 있다면 생략한다.
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
				pq.push(make_pair(viaCost, nodes[here][i].second));
			}
		}
	}
}

int main(void)
{
	int n, m, init;
	cin >> n >> m;

	// 초기화, 모든 거리를 우선 INF로 하여 이동을 불가하게 한다.
	for (int i = 1; i <= n; i++)
	{
		// 초기화 단계에서 INF로 처리를 해두면 갈 수 없는 부분에 대해 예외 처리를 할 필요가 없다.
		dist[i] = INF;
	}

	cin >> init;

	// 그래프를 입력받아 노드를 채운다.
	for (int i = 1; i <= m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		nodes[start].push_back(make_pair(cost, end));
	}

	Dijkstara(init);
	dist[init] = 0;
	// starts에 있는 시작점을 받아서 하나씩 처리한다.
	for (int i = 1; i <= n; i++)
	{
		// 출력 형식을 맞춰주기 위해 10000000이면 INF로 출력
		if (dist[i] == 10000000)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
	return 0;
}