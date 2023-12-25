#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
	A->B 문제
	- 두 값을 주고 A가 B로 같게 한다
	- 2배 연산
	- 1을 우측에 추가한다
*/


int bfs(long long start, long long end)
{
	queue<pair<long long, long long>> q;
	q.push(make_pair(start, 1));
	while (!q.empty())
	{
		pair<long long, long long> now = q.front();
		q.pop();

		if (now.first == end)
			return now.second;

		if (now.first * 2 <= end)
		{
			q.push(make_pair(now.first * 2, now.second +1));
		}

		if ((now.first * 10) + 1 <= end)
		{
			q.push(make_pair((now.first * 10) + 1, now.second + 1));
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long a, b;

	cin >> a >> b;
	cout << bfs(a, b) << '\n';
	return 0;
}