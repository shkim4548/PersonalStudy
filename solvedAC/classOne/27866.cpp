#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string input;
	int index;

	getline(cin, input);
	cin >> index;
	cout << input[index - 1] << '\n';
}