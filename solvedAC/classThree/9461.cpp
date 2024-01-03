#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<long long> container(101);
	int testCase;
	cin >> testCase;

	for (int j = 0; j < 100; j++)
	{
		if (j < 3)
		{
			container[j] = 1;
		}

		else
		{
			container[j] = container[j - 2] + container[j - 3];
		}
	}

	for (int i = 0; i < testCase; i++)
	{
		int n;
		cin >> n;

		cout << container[n - 1] << '\n';
	}
	return 0;
}