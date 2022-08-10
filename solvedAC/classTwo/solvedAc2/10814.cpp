#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool customSort(pair<int, string> param1, pair<int, string> param2) {
	//등록 순서 저장 -> 인자의 첫번째 요소만으로 정렬할 것
	return param1.first < param2.first;
}

int main(void) {
	int n;
	string inputString;
	int inputInt;
	vector<pair<int, string>> member;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//pair구성으로 입력받음
		cin >> inputInt >> inputString;
		member.push_back(make_pair(inputInt, inputString));
	}

	sort(member.begin(), member.end(), customSort);

	for (int i = 0; i < n; i++) {
		cout << member[i].first << " " << member[i].second << '\n';
	}

	return 0;
}