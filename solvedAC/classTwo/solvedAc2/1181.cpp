#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string a, string b);

int main(void) {
	int n;
	string a;
	cin >> n;
	vector<string> str;
	for (int i = 0; i < n; i++) {
		cin >> a;
		str.push_back(a);
	}

	//vector �ߺ�����
	str.erase(unique(str.begin(), str.end()), str.end());
	//custom sorting ����
	sort(str.begin(), str.end(), compare);
	sort(str.begin(), str.end());

	for (int i = 0; i < str.size(); i++) {
		cout<<str[i]<<'\n';
	}

	return 0;
}

//custom sorting�� ���� ����� ���� �Լ� ����
bool compare(string a, string b) {
	return a.size() < b.size();
}