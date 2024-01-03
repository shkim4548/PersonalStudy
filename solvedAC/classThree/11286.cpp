#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

/*
	구조체를 이용한 우선순위 큐 정렬 기준 정하기
*/

struct absStruct {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, input;
	priority_queue<int, vector<int>, absStruct> pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}

	return 0;
}