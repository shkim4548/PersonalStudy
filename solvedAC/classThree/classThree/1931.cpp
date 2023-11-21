#include <iostream>
#include <vector>
#include <algorithm>
// next_Permutaition -> 
using namespace std;

/*
	풀이전략
	- 끝나는 시간이 빠르면, 시작 시간도 빠르다.
	- 그리디는 결국 정렬이다.
*/

bool Asc(pair<int, int> a, pair<int, int> b) 
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, start, end, res = 0, now = 0;
	cin >> n;
	vector<pair<int, int>> meetings(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> meetings[i].first >> meetings[i].second;
		// 위 아래 같은 코드
		//cin >> start >> end;
		//meetings.push_back(make_pair(start, end));
	}

	sort(meetings.begin(), meetings.end(), Asc);

	// 반복 탐색 전 초기화
	for (int i = 0; i < n; i++) 
	{
		if (now > meetings[i].first)
			continue;

		now = meetings[i].second;
		res++;
	}

	cout << res << '\n';
}