#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DfsBack(int start, int n, int k, vector<int>& numbers, vector<int>& permutation, vector<bool>& visited)
{
	if (permutation.size() == k)
	{
		for (int num : permutation)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++)
	{
		permutation.push_back(numbers[i]);
		DfsBack(i, n, k, numbers, permutation, visited);
		permutation.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> numbers(n);
	vector<bool> visited(n, false);
	vector<int> permutation;

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	// 정렬 및 중복 제거
	sort(numbers.begin(), numbers.end());

	n = numbers.size();
	DfsBack(0, n, k, numbers, permutation, visited);
	return 0;
}