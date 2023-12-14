#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 100000000;
const int MAX = 101;
int graph[MAX][MAX] = { 0 };

void FloydWarshall(int size)
{
	// 알고리즘 작성 부분
	// k : 거쳐가는 부분
	for (int k = 1; k <= size; k++)
	{
		// i : 출발지 노드
		for (int i = 1; i <= size; i++)
		{
			// j : 도착지 노드
			for (int j = 1; j <= size; j++)
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	// 순회 결과 출력하기
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (graph[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, start, end, cost;
	cin >> n;
	cin >> m;
	// 그래프 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}

	// 그래프 입력받기
	for (int i = 1; i <= m; i++) 
	{
		cin >> start >> end >> cost;
		//graph[start][end] = cost;
		graph[start][end] = min(graph[start][end], cost);
	}

	FloydWarshall(n);

	return 0;
}