#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<int> hotel;
	int h, w, n, t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		for (int j = 1; j <= w; j++) {
			for (int k = 1; k <= h; k++) {
				hotel.push_back(100 * k + j);
			}
		}
		cout << hotel[n] << '\n';
		hotel.clear();
	}
	cout << '\n';
	for (int i = 0; i < hotel.size(); i++)
		cout << hotel[i] << '\n';
	return 0;
	*/
	int n, w, h, person = 1, inputPerson, one = 1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> h >> w >> inputPerson;
		for (int j = 1; j <= 10000; j++) {
			//cout << person << " " << j * 100 + one << '\n';
			if (person == inputPerson) {
				cout << j * 100 + one << '\n';
				person = 1;
				one = 1;
				break;
			}
			if (j * 100 + one == h * 100 + one) {
				one++;
				j = 0;
			}
			person++;
		}
	}
	return 0;
}