#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	부녀회장 문제
	- 다이나믹 프로그래밍 문제

*/

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCase;
	int container[15][15] = { 0 };
	for (int i = 0; i < 15; i++)
	{
		container[0][i] = i;
	}

	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			container[i][j] = container[i - 1][j] + container[i][j - 1];
		}
	}

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << container[a][b] << '\n';
	}

	return 0;
}