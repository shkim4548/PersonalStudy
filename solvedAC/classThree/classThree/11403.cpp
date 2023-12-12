#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	플로이드 워셜 알고리즘
	- 다익스트라 알고리즘과 같이 최단거리를 구할 수 있는 알고리즘
	- 모든 정점에서 시작하여 모든 정점으로 도착하는 최단 경로를 한번에 구한다.
	- 3중 for문을 쓰기에 느리다 굉장히
*/

const int MAX = 101;
const int INF = 10000000;
int graph[MAX][MAX];

void FloydWarshall(int size)
{
	// k : 거쳐가는 노드
	for (int k = 0; k < size; k++)
	{
		// i : 출발지 노드
		for (int i = 0; i < size; i++)
		{
			// j : 도착지 노드
			for (int j = 0; j < size; j++)
			{
				if (graph[i][k] && graph[k][j])
					graph[i][j] = 1;
			}
		}
	}

	// 출력
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
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

	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	FloydWarshall(n);
	return 0;
}