#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

/*------------------------------
	c++ 반올림을 해봅시다
	오사오입 문제는 C++와는 관계가 없습니다
	문제을 제대로 읽고 0인 경우를 처리해야한다.
--------------------------------*/

int main(void) {
	deque<int> d;
	int n, input, sum = 0;
	float trimmedAvg = 0, avg = 0;
	cin >> n;

	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> input;
		d.push_back(input);
		sum += input;
	}

	// 절사평균을 계산하는 부분
	trimmedAvg = ((float)(n * 15) / 100);
	sort(d.begin(), d.end());

	// 절사하기
	for (int i = 0; i < round(trimmedAvg); i++) {
		d.pop_back();
		d.pop_front();

	}
	for (int i = 0; i < n; i++) {
		if (d.empty())
			break;
		avg += d.front();
		d.pop_front();
	}
	int bottom = n - 2 * (round(trimmedAvg));
	cout << round((avg / bottom)) << '\n';
	return 0;
}