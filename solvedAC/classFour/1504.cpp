#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 100000000;
const int MAX = 801; // 정점의 개수가 800이므로 배열 크기를 조정
vector<pair<int, int>> nodes[MAX];
int dist[MAX];
int n, m;

/*
    특정 정점을 지나는 다익스트라 알고리즘
    - 
*/

void dijkstra(int start)
{
    // 함수를 여러번 돌리기 때문에 돌릴때 마다 초기화를 다시해줘야한다
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (int i = 0; i < nodes[here].size(); i++)
        {
            int viaCost = cost + nodes[here][i].first;

            if (viaCost < dist[nodes[here][i].second])
            {
                dist[nodes[here][i].second] = viaCost;
                pq.push(make_pair(viaCost, nodes[here][i].second));
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;



    for (int i = 1; i <= m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        nodes[start].push_back(make_pair(cost, end));
        nodes[end].push_back(make_pair(cost, start));
    }

    int firstPoint, secondPoint;
    cin >> firstPoint >> secondPoint;

    dijkstra(1);
    int toFirst = dist[firstPoint];
    int toSecond = dist[secondPoint];

    dijkstra(firstPoint);
    int firstToSecond = dist[secondPoint];
    int firstToN = dist[n];

    dijkstra(secondPoint);
    int secondToN = dist[n];

    int res = INF;

    res = min(res, toFirst + firstToSecond + secondToN);
    res = min(res, toSecond + firstToSecond + firstToN);

    if (res >= INF || firstToSecond == INF)
        cout << -1 << '\n';
    else
        cout << res << '\n';

    return 0;
}
