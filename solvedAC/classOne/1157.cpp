#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<char, int> a, pair<char, int> b)
{
	return a.second > b.second;
}

int main(void)
{
	int ch[26] = { 0, };
	int maxCount = 0, cnt = 0;
	vector<pair<char, int>> counts;
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			if (input[i] == j || input[i] == j + 32)
				ch[j - 65]++;
		}
	}
	int max = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < ch[i])
		{
			max = ch[i];
			maxCount = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (max == ch[i])
			cnt++;
	}
	if (cnt > 1)
		cout << "?" << '\n';
	else
		cout << char(65 + maxCount);
	return 0;
}