#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ascSequence(int a, int b) {
	return a < b;
}

int main(void) {
	int n, input, sum = 0, res = 0;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end(), ascSequence);
	for (int i = 0; i < n; i++) {
		sum += v[i];
		res += sum;
		//cout << v[i] << ", " << sum << ", " << res << " ";
		//cout << v[i] << '\n';
	}
	cout << res << '\n';
	return 0;
}