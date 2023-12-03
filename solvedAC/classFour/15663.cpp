#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int n, int k, vector<int>& numbers, vector<int>& permutation, vector<bool>& visited) 
{
	vector<int> temp;
	if (permutation.size() == k)
	{
		for (int num : permutation)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		visited[i] = true;
		permutation.push_back(numbers[i]);
		dfs(n, k, numbers, permutation, visited);
		visited[i] = false;	// 백트래킹 : 이전상태로 돌아간다.
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

	// 정렬 후 중복을 제거한다.
	sort(numbers.begin(), numbers.end());

	// 중복제거
	numbers.erase((unique(numbers.begin(), numbers.end())));
	n = numbers.size();
	dfs(n, k, numbers, permutation, visited);
	return 0;
}