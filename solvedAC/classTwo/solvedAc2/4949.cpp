#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

bool validBalance(string input) {
	stack<char> small;
	stack<char> large;
	
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(')
			small.push('(');

		else if (input[i] == '[')
			large.push('[');

		else if (input[i] == ')')
			small.pop();

		else if (input[i] == ']')
			large.pop();
	}

	if (small.empty() && large.empty())
		return true;

	else
		return false;
}

int main(void) {
	string input;
	vector<string> vs;
	vector<stack<char>> v;

		getline(cin, input);
		vs.push_back(input);
	

	while(!vs.empty())
		validBalance(input);
}