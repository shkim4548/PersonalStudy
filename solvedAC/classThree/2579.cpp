#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	다이나믹 프로그래밍
	1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
	2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
	3. 마지막 도착 계단은 반드시 밟아야 한다.
*/

int Max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n, sum = 0;
	cin >> n;
	vector<int> stair(301);
	vector<int> res(301);

	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}

	/* 마지막 칸을 반드시 밟는 방법
		1. 전칸을 밟고 마지막을 밟는 경우	-> (n-3) + (n-1) + n -> 연속 3칸을 방지
		2. 전전칸을 밟고 마지막을 밟는 경우 -> (n-2) + (n)
	*/
	res[0] = stair[0];
	res[1] = Max(stair[0] + stair[1], stair[1]);
	res[2] = Max(stair[0] + stair[2], stair[1] + stair[2]);
	for (int i = 3; i < n; i++) {
		res[i] = Max(res[i - 2] + stair[i], stair[i - 1] + stair[i] + res[i - 3]);
	}

	cout << res[n - 1] << '\n';
	return 0;
}