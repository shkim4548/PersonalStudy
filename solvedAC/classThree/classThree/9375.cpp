#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;



int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m, cnt = 1;
		map<string, int> container;
		cin >> m;
		string name, type;

		for (int j = 0; j < m; j++)
		{
			cin >> name >> type;
			if (container.find(type) != container.end())
				container[type]++;

			else
				container[type] = 1;
		}

		auto iter = container.begin();
		for (; iter != container.end(); iter++)
			cnt *= (iter->second) + 1;
		cout << cnt - 1 << '\n';
	}
	return 0;
}