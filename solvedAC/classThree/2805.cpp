#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long int res = 0;

/*
	이진탐색 범위 내부에서
	- 중간값을 찾는다. 거기서 하나씩 내리면서 찾는다.
	- 내리는 대상은 인덱스이다.
*/

void binarySearch(vector<int>& v, int start, int end)
{
	while (start <= end)
	{
		long long int sum = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
		{
			// 잘린다는 전제하에 본다, 실질적으로 문제를 푸는 부분이다.
			if (v[i] > mid)
			{
				sum += v[i] - mid;
			}
		}

		if (sum < m)
		{
			end = mid - 1;
		}
		else
		{
			res = mid;
			start = mid + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> trees;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		trees.push_back(tmp);
	}

	// 이분탐색하려면 정렬해야합니다.
	sort(trees.begin(), trees.end());
	int start = 0;
	int end = *max_element(trees.begin(), trees.end());

	binarySearch(trees, start, end);
	cout << res << '\n';
	return 0;
}