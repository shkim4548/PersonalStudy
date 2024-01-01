#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string input;

	// 입력을 while 문으로 받아야한다.
	while (true)
	{
		getline(cin, input);
		stack<int> container;

		if (input[0] == '.')
		{
			break;
		}

		for (int i = 0; i < input.length() - 1; i++)
		{
			if (input[i] == '(')
				container.push('(');
			if (input[i] == '[')
				container.push('[');

			if (input[i] == ']')
			{
				if (!container.empty() && container.top() == '[')
					container.pop();
				else
				{
					printf("no\n"); 
					break;
				} // "]hello[" 같은 예외 문장들 방지
			}

			if (input[i] == ')')
			{
				if (!container.empty() && container.top() == '(')
					container.pop();
				else
				{
					printf("no\n"); 
					break;
				} // ")hello(" 같은 예외 문장들 방지
			}

			if (container.empty() && i == input.length() - 2)
				printf("yes\n"); // str[str.length() - 1] = '.' 이므로 검사할 필요가 없다.
			else if (!container.empty() && i == input.length() - 2)
				printf("no\n");
		}
	}
	return 0;
}