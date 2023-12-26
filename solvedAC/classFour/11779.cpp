#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 1001;
const int INF = 100000000;
vector<pair<int, int>> nodes[MAX];
vector<bool> visited[MAX];
pair<int,int> dist[MAX];
vector<int> edges[MAX];
int cnt = 0;

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	cnt = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here].first < cost)
			continue;

		for (int i = 0; i < nodes[here].size(); i++)
		{
			int viaCost = cost + nodes[here][i].first;
			if (viaCost < dist[nodes[here][i].second].first)
			{
				edges[here].push_back(here);
				dist[nodes[here][i].second].first = viaCost;
				dist[nodes[here][i].second].second++;
				pq.push(make_pair(viaCost, nodes[here][i].second));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		dist[i].first = INF;
	}

	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		nodes[start].push_back(make_pair(cost, end));
	}
	
	int startPoint, endPoint;
	cin >> startPoint >> endPoint;

	dijkstra(startPoint);
	cout << dist[endPoint].first << '\n';
	cout << dist[endPoint].second + 1<< '\n';
	return 0;
}