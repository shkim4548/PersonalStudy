#include <iostream>
#include <vector>
using namespace std;

bool isEqual(vector<int>& v1, vector<int>& v2) {

}

int main(void) {
	int input;
	vector<int> v;

	vector<int> asc = { 1,2,3,4,5,6,8, };
	vector<int> desc = { 8,7,6,5,4,3,2,1 };


	for (int i = 0; i < 8; i++) {
		cin >> input;
		v.push_back(input);
	}
	
	if ()
		cout << "ascending" << '\n';
	else if (v == desc)
		cout << "descending" << '\n';
	else
		cout << "mixed" << '\n';
}