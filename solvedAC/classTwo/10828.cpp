#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> s;

void spush(int value) {
	s.push(value);
}

void spop() {
	if (s.empty())
		cout << -1 << '\n';

	else {
		cout << s.top() << '\n';
		s.pop();
	}
}

void ssize() {
	cout << s.size() << '\n';
}

void sempty() {
	cout << (int)s.empty() << '\n';
}

void stop() {
	if (s.empty())
		cout << -1 << '\n';

	else {
		cout << s.top() << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string command;
	int n, value;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push") {
			cin >> value;
			spush(value);
		}

		else if (command == "pop") {
			spop();
		}

		else if (command == "size") {
			ssize();
		}

		else if (command == "empty") {
			sempty();
		}
		else if (command == "top") {
			stop();
		}
	}

	return 0;
}