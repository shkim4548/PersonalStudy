#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> d;

void push_back(int value) {
	d.push_back(value);
}

void push_front(int value) {
	d.push_front(value);
}

void pop_front() {
	if (d.empty())
		cout << -1 << '\n';
	else {
		cout << d.front() << '\n';
		d.pop_front();
	}
}

void pop_back() {
	if (d.empty())
		cout << -1 << '\n';
	else {
		cout << d.back() << '\n';
		d.pop_back();
	}
}

void size() {
	cout << d.size() << '\n';
}

void empty() {
	if (d.empty())
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}

void front() {
	if (d.empty())
		cout << -1 << '\n';
	else
		cout << d.front() << '\n';
}

void back() {
	if (d.empty())
		cout << -1 << '\n';
	else
		cout << d.back() << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, value;
	string command;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push_back") {
			cin >> value;
			push_back(value);
		}
		else if (command == "push_front") {
			cin >> value;
			push_front(value);
		}

		else if (command == "pop_front")
			pop_front();

		else if (command == "pop_back")
			pop_back();

		else if (command == "size")
			size();

		else if (command == "empty")
			empty();

		else if (command == "front")
			front();

		else if (command == "back")
			back();
	}
	return 0;
}