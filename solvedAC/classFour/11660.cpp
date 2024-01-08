#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1025;
int matrix[MAX][MAX];

/*
	부분합 문제
*/

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, t;

	// 행렬을 입력받는 동시에 부분합을 구한다.
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> t;
			matrix[i + 1][j + 1] = matrix[i][j + 1] + matrix[i + 1][j] - matrix[i][j] + t;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		cout << matrix[y2][x2] - matrix[y1 - 1][x2] - matrix[y2][x1 - 1] + matrix[y1 - 1][x1 - 1] << '\n';
	}

	return 0;
}