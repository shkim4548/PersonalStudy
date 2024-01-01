#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void qpush(int value) {
	q.push(value);
}

void qpop() {
	if (q.empty())
		cout << -1 << '\n';

	else {
		cout << q.front() << '\n';
		if (!q.empty())
			q.pop();
	}
}

void qsize() {
	cout << q.size() << '\n';
}

void qempty() {
	cout << (int)q.empty() << '\n';
}

void qfront() {
	if (!q.empty())
		cout << q.front() << '\n';
	else
		cout << -1 << '\n';
}

void qback() {
	if (!q.empty())
		cout << q.back() << '\n';
	else
		cout << -1 << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, value;
	string command;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push") {
			cin >> value;
			qpush(value);
		}
		else if (command == "pop")
			qpop();

		else if (command == "size")
			qsize();
		else if (command == "empty")
			qempty();
		else if (command == "front")
			qfront();
		else if (command == "back")
			qback();
	}
	return 0;
}