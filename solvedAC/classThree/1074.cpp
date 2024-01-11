#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, r, c;
int cnt = 0;

/*
	분할 정복
	- 같은 사분면에 있는지 확인하는 방법
	- 큰 범위를 먼저 구하고, 작은 범위로 들어가는 방식이다
*/

void dac(int x, int y, int size)
{
	// 목표지점에 도착시 나가야한다 혹시 모르니 한번 더 체크
	if (c == x && r == y)
	{
		cout << cnt;
		return;
	}

	// 찾으려는 열과 행이 4분만 안에 있는 경우
	else if (c < x + size && r < y + size && c >= x && r >= y)
	{
		dac(x, y, size / 2);
		dac(x + size / 2, y, size / 2);
		dac(x, y + size / 2, size / 2);
		dac(x + size / 2, y + size / 2, size / 2);
	}

	// 없다면 숫자 카운트
	else
	{
		cnt += size * size;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> r >> c;
	dac(0, 0, pow(2, n));
	return 0;
}