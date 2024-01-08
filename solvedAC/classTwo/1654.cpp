#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	이분 탐색 문제
*/

int n, k;
unsigned int res = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<unsigned int> cables;
	unsigned int maxi = 0;

	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		unsigned int tmp;
		cin >> tmp;
		cables.push_back(tmp);
		maxi = max(maxi, cables[i]);
	}

	//sort(cables.begin(), cables.end());
	unsigned int start = 1, mid;
	//int end = *max_element(cables.begin(), cables.end());
	unsigned int end = maxi;
	//binarySearch(cables, start, end);
	while (start <= end)
	{
		mid = (start + end) / 2;
		unsigned int sum = 0;
		for (int i = 0; i < k; i++)
		{
			// mid로 나눈 몫을 저장
			sum += cables[i] / mid;
		}

		if (sum >= n)
		{
			// mid로 나눈 값이 n보다 크거나 같다면, start를 움직여 더 긴 경우 찾음
			start = mid + 1;
			// n개를 만들 수 있을 때, 답을 더 큰 값으로 계속 갱신
			res = max(res, mid);
		}
		else
		{
			// 현재 mid로 나눈 값이 n보다 작다면, end를 움직여 길이가 더 짧은경우 검사
			end = mid - 1;
		}
	}

	cout << res << '\n';
	return 0;
}