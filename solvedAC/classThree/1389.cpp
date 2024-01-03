#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 101;
const int INF = 100000000;
int graph[MAX][MAX];
int dist[MAX][MAX] = { 0 };

void FloydWarshall(int size)
{
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (graph[i][k] && graph[k][j])
				{
					graph[i][j] = 1;
					dist[i][j]++;
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, input;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = INF;
		}
	}

	// 그래프를 입력받는다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a, b;
			cin >> a >> b;
			graph[a][b] = 1;
		}
	}
	
	return 0;
}