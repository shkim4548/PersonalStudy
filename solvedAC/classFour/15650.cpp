#include<iostream>
#include<vector>
using namespace std;

const int MAX = 9;
vector<int> vec(MAX);
vector<int> visited(MAX);
int a, b;

void back(vector<int> v, int cnt, int index)
{
	if (vec.size() == b)
	{
		for (int i = 0; i < cnt; i++) 
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = index; i < v.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			vec.push_back(v[i]);
			back(v, cnt + 1, i);
			vec.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	vector<int> v;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		v.push_back(i);
	}
	back(v, 0, 0);

}
