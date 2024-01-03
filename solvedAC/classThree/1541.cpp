#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	string input;
	int res = 0;
	bool sub = false;
	cin >> input;

	string tmp = "";
	for (int i = 0; i <= input.size(); i++)
	{
		// 숫자를 파싱한다
		if (input[i] == '+' || input[i] == '-' || input[i] == '\0')
		{
			if (sub == false)
			{
				int t = stoi(tmp);
				res += t;
				tmp = "";
				if (input[i] == '-')
				{
					sub = !sub;
				}
			}
			else
			{
				int t = stoi(tmp);
				res -= t;
				tmp = "";
			}
		}
		else
		{
			tmp += input[i];
		}
	}

	cout << res << '\n';
	return 0;
}