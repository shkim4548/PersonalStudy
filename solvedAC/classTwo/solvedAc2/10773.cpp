#include <iostream>
#include <stack>
using namespace std;

/*--------------------------
	사실상 그냥 스택문제
----------------------------*/

int main(void) {
	int n, m, sum = 0;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 0)
			s.pop();

		else {
			s.push(m);
		}
	}

	for (int i = 0; i < n; i++) {
		if (s.empty())
			break;

		sum += s.top();
		s.pop();
	}
	cout << sum << '\n';
	return 0;
}