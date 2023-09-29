#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*----------------------------------------
	stable_sort
	입력 순서가 보장되는 sort 함수이다
------------------------------------------*/

bool customSort(pair<int, string> p1, pair<int, string> p2) {
	return p1.first < p2.first;
}

int main(void) {
	int n;
	string inputString;
	int inputInt;
	vector<pair<int, string>> member;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inputInt >> inputString;
		member.push_back(make_pair(inputInt, inputString));
	}

	stable_sort(member.begin(), member.end(), customSort);

	for (int i = 0; i < n; i++) {
		cout << member[i].first << " " << member[i].second << '\n';
	}

	return 0;
}