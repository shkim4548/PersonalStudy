#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int sequence[MAX] = { 0 };
int dp[MAX] = { 0 };	// 메모이제이션 기법을 사용하기 위한 배열

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, last = 0, length = 1;
	cin >> n;

	// 수열을 입력받는다
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	// 입력받은 수열에서 증가하는 수열을 찾는다
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (sequence[j] < sequence[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		last = max(last, dp[i]);
	}

	cout << last << '\n';
	return 0;
}