#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/*----------------------------
	스택으로 짝맞추기
------------------------------*/

bool IsVps(const string& str) {
	stack<char> sc;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			sc.push('(');
		}


		else if (str[i] == ')') {
			if (sc.empty())
				return false;
			
				sc.pop();
		}		
	}
	if (sc.empty())
		return true;
	else
		return false;
}

int main(void) {
	int n;
	string input;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> input;

		if (IsVps(input))
			cout << "YES" << '\n';
		else if (IsVps(input) == false)
			cout << "NO" << '\n';
	}

	return 0;
}