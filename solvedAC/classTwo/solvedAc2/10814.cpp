#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool customSort(pair<int, string> param1, pair<int, string> param2) {
	//��� ���� ���� -> ������ ù��° ��Ҹ����� ������ ��
	return param1.first < param2.first;
}

int main(void) {
	int n;
	string inputString;
	int inputInt;
	vector<pair<int, string>> member;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//pair�������� �Է¹���
		cin >> inputInt >> inputString;
		member.push_back(make_pair(inputInt, inputString));
	}

	sort(member.begin(), member.end(), customSort);

	for (int i = 0; i < n; i++) {
		cout << member[i].first << " " << member[i].second << '\n';
	}

	return 0;
}