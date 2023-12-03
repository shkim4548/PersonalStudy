#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DfsBack(int n, int k, int start, vector<int>& permutation)
{
	if (permutation.size() == k) 
	{
		sort(permutation.begin(), permutation.end());
		for (int num : permutation)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++) 
	{
		permutation.push_back(i);
		DfsBack(n, k, i, permutation);
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
	vector<int> permutation;

	DfsBack(n, k, 1, permutation);
	
	return 0;
}