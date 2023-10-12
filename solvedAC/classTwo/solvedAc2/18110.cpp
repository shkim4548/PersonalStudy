#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*------------------------------
	c++ 반올림을 해봅시다
	오사오입 문제는 C++와는 관계가 없습니다
	문제을 제대로 읽고 0인 경우를 처리해야한다.
	부동소수점 오차
--------------------------------*/

\
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, input, sum = 0;
	float trimmed = 0, res = 0;
	vector<int> v;
	cin >> n;

	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	trimmed = round(n * 0.15);
	sort(v.begin(), v.end());
	for (int i = trimmed; i < n - trimmed; i++) {
		res += v[i];
	}
	
	res /= n - (trimmed * 2);
	cout << round(res) << '\n';
}