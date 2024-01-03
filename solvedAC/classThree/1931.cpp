#include <iostream>
#include <vector>
#include <algorithm>
// next_Permutaition -> 
using namespace std;

/*
	Ǯ������
	- ������ �ð��� ������, ���� �ð��� ������.
	- �׸���� �ᱹ �����̴�.
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
		// �� �Ʒ� ���� �ڵ�
		//cin >> start >> end;
		//meetings.push_back(make_pair(start, end));
	}

	sort(meetings.begin(), meetings.end(), Asc);

	// �ݺ� Ž�� �� �ʱ�ȭ
	for (int i = 0; i < n; i++) 
	{
		if (now > meetings[i].first)
			continue;

		now = meetings[i].second;
		res++;
	}

	cout << res << '\n';
}