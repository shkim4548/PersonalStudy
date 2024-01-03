#include <iostream>
#include <vector>
using namespace std;

const int MAX = 12;
int cnt = 1, n;
vector<int> memo(MAX);

int sum(int start) 
{
	if (start <= 1)
		return 1;

	if (start == 2)
		return 2;

	return sum(start - 1) + sum(start - 2) + sum(start - 3);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int start;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start;
		cout << sum(start) << '\n';
	}
	return 0;
}