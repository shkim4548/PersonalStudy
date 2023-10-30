#include <iostream>
#include <vector>
using namespace std;

/*
	다이나믹 프로그래밍
	1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
	2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
	3. 마지막 도착 계단은 반드시 밟아야 한다.
*/

int main(void) {
	int n, input, sum = 0;
	cin >> n;
	vector<int> maxVec;
	vector<int> stair(n);

	for (int i = 0; i < n; i++) {
		cin >> input;
		stair.push_back(input);
	}
}