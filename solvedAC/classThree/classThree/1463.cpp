#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	if - else 문의 함정
	최소값이란 점은 항상 답이 되는 자료구조는 vector등을 생각해야한다.
	바텀업
	- 배열을 선언하고 하나씩 채워나가는 방식
*/

int main(void) {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n] << '\n';
	return 0;
}