#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 505;
int triangle[MAX][MAX] = { 0, };

/*
	정수 삼각형
	- 아래 또는 오른쪽 아래로만 내려갈 수 있다.
	- 내려오면서 합이 최대가 되는 경로

	풀이 방법 접근
	- 첫번째 열은 무조건 위에서 내려올 수 밖에 없다
	- i == j인 곳은 무조건 대각선
	- 위 두가지 경우를 제외시 아래 또는 오른쪽 아래중 큰 값
*/

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	// 정수 삼각형을 입력받는다.
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}

	int maxInt = triangle[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i + 1; j++)
		{
			if (j == 1)
				triangle[i][j] += triangle[i - 1][j];
			else if (j == i)
				triangle[i][j] += triangle[i - 1][j - 1];
			else
				triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);

			maxInt = max(maxInt, triangle[i][j]);
		}
	}

	cout << maxInt << '\n';
}
