#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 500;
int n, m, b;
int graph[MAX][MAX];
int t = 99999999, line = 99999999;

int main(void)
{
	cin >> n >> m >> b;	// 각 입력은 배열의 크기와 인벤토리 상의 아이템 수
	
	// 행렬 입력, 입력받으면서 최고 높이와 최저 높이를 저장한다
	int max = 0, min = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			if (max < graph[i][j])
				max = graph[i][j];
			else if (min > graph[i][j])
				min = graph[i][j];
		}
	}

	// 입력받은 행렬 처리
	for (int i = min; i <= max; i++)
	{
		int remove = 0;
		int stack = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (graph[j][k] > i)
					remove += graph[j][k] - i;	// 깎기
				else if (graph[j][k] < i)
					stack += i - graph[j][k];	// 채우기
			}
		}
		if (stack <= remove + b)
		{
			int tmp = remove * 2 + stack;
			if (t > tmp)
			{
				t = tmp;
				line = i;
			}
			else if (t == tmp)
				line = i;
		}
	}

	cout << t << ' ' << line;
	return 0;
}