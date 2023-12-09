#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
	OX 퀴즈
	- 
*/

int main(void)
{
	int n, sum = 0;
	vector<vector<string>> container;
	string input;
	cin >> n;
	int temp = 1;
	// 입력받기
	for (int i = 0; i < n; i++) 
	{
		cin >> input;
		for (int j = 0; j < input.size(); j++)
		{
			if (input[j] == 'O')
			{
				sum += temp;
				temp++;
			}
			else if(input[j] == 'X')
			{
				temp = 1;
			}
		}
		cout << sum << '\n';
		sum = 0;
		temp = 1;
	}
	return 0;
}