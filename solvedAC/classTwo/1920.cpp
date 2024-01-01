#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*---------------------------------------------------------------------
	이진탐색
	vector를 파라미터로 주면 안됩니다!
	vector를 함수의 인자로 줄 때 그냥 주면 복사를 해버려서 
	vector의 길이만큼 시간이 걸립니다. 대신 참조형으로 주면 됩니다.
-----------------------------------------------------------------------*/

bool binarySearch(vector<int>& v, int key) {
	int low = 0;
	int high = v.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == v[mid])
			return true;

		else if (key < v[mid])
			high = mid - 1;
		else if (key > v[mid])
			low = mid + 1;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, input, m;
	vector<int> v1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v1.push_back(input);
	}
	sort(v1.begin(), v1.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (binarySearch(v1, input))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}