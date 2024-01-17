#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;

/*
	후위 표기식
	- 괄호가 있나 없나를 구분해줘야한다.
		1. '(' 는 push
		2. ')' 가 나타나면 '(' 만날때까지 pop후 출력
	- 연산 우선순위 또한 고려해줘야한다.
		1. top보다 우선순위가 크면 push
		2. top보다 우선순위가 작거나 같으면 pop
*/

int priority(char a)
{
	if (a == '+' || a == '-')
		return 1;
	if (a == '*' || a == '/')
		return 2;

	// '('는 원래 우선순위가 가장 높지만 top에 '('가 있는 경우를 고려해 0으로 설정
	return 0;
}

int main(void)
{
	stack<char> s;

	string input, ans;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		// 1. 피연산자는 출력
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			ans += input[i];
			continue;
		}
		// 2. 열린 괄호를 만나면 푸싱
		if (input[i] == '(' || s.empty())
		{
			s.push(input[i]);
			continue;
		}

		// 3. 닫힌괄호를 보면 열린 괄호를 만날 때까지 출력한다.
		if (input[i] == ')')
		{
			while (s.top() != '(')
			{
				ans += s.top();
				s.pop();
			}
			s.pop();
			continue;
		}

		// 4. 연산자 우선순위를 따져서 높은쪽을 push한다
		if (priority(s.top()) < priority(input[i]))
		{
			s.push(input[i]);
		}

		// 5. 우선 순위가 낮으면 pop후 반복
		else
		{
			while (!s.empty() && priority(s.top()) >= priority(input[i]))
			{
				ans += s.top();
				s.pop();
			}
			s.push(input[i]);
		}
	}
		// 스택이 전부 비었다면 출력한다.
		while (!s.empty())
		{
			ans += s.top();
			s.pop();
		}
	std::cout << ans << '\n';
	return 0;
}