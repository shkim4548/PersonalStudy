#include <iostream>
#include <vector>
using namespace std;

/*
	카잉달력
	- 1:1 ->1
	- 10 : 10 -> 10
	- 1 : 11 -> 11
	- 2 : 12 -> 12
	- 3 : 1 -> 13
	- 3 : 2 -> 14

	풀이 전략
	1. 3중 for문을 사용하면 시간초과
	2. 최대공약수, 최대공배수 처리
		51 -> 10(주어진 n)이 5번 + 1
		52 -> 12(주어진 m)이 5번 + 1
		주의사항은 나머지가 0이면 최대값으로 바꾸어야한다.
		답은 m,n의 값이 동시에 나누어지는 최소값
*/

const int MAX = 40001;
vector<pair<int, int>> cal(MAX);
int xCount, yCount;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int m, n, x, y;
		int res = -1;
		cin >> m >> n >> x >> y;
		int maxInt = lcm(m, n);
		for (int i = x; i <= maxInt; i += m)
		{
			int ny = i % n;
			if (ny == 0)
				ny = n;

			if (ny == y)
			{
				res = i;
				break;
			}
		}
		cout << res <<'\n';
	}
	return 0;
}