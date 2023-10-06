#include <iostream>
#include <deque>
using namespace std;

deque<int> d;

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}

	while (true) {
		if (d.size() == 1)
			break;
		d.pop_front();
		d.push_back(d.front());
		d.pop_front();
	}
	cout << d.front() << '\n';
	return 0;
}