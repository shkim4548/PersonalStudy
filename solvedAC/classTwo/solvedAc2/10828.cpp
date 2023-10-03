#include <iostream>
#include <string>
#include <stack>
using namespace std;

void customStack(string command, int n = 0) {
	stack<int> stack_;

	if (command == "push")
		stack_.push(n);

	else if (command == "empty") {
		if (stack_.empty())
			cout << 1 << '\n';

		else
			cout << 0 << '\n';
	}

	else if (command == "size")
		cout << stack_.size() << '\n';

	else if (command == "top")
		cout << stack_.top() << '\n';

	else if (command == "pop") {
		if (stack_.size() == 0)
			cout << -1 << '\n';
		else
			cout << stack_.top() << '\n';
	}
}

int main(void) {
	int n, count = 0, input = 0;
	cin >> n;
	string command;
	while (true) {
		if (n == count)
			break;
		scanf_s("%s %d", command, &input);

		customStack(command, input);
	}
	return 0;
}