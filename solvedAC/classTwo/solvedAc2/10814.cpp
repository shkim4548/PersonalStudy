#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <map>
using namespace std;

bool compare()

int main(void) {
	int n, age;
	string name;
	map<int, string> list;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		list.insert({ age, name });
	}
}