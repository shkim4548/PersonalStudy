#include<iostream>
#include<vector>

using namespace std;

vector<int> vec;
bool visited[4];
void back(vector<int> v, int cnt, int index)
{
	if (vec.size() == 3)
	{
		for (auto k : vec) cout << k << " ";
		cout << '\n';
		return;
	}

	for (int i = index; i < v.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			vec.push_back(v[i]);
			back(v, cnt + 1, i);
			vec.pop_back();
			visited[i] = 0;
		}
	}
}

int main()
{
	vector<int> v = { 1,2,3,4 };

	back(v, 0,0);

}
