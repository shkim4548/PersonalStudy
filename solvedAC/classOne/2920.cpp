#include <iostream>
#include <vector>
using namespace std;

bool isEqual(vector<int>& v1, vector<int>& v2) 
{
	return (v1.size() == v2.size() &&
		std::equal(v1.begin(), v1.end(), v2.begin()));
}

int main(void) 
{
	vector<int> input(8);
	vector<int> asc = { 1,2,3,4,5,6,7,8 };
	vector<int> desc = { 8,7,6,5,4,3,2,1 };

	for (int i = 0; i < 8; i++)
	{
		int a;
		cin >> a;
		input[i] = a;
	}

	if (input == asc)
		cout << "ascending" << '\n';
	else if (input == desc)
		cout << "descending" << '\n';
	else
		cout << "mixed" << '\n';

	return 0;
}