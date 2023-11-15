#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	char target;
	int cnt = 0;

	getline(cin, s);
	// cout << s.length() << '\n';
	if (s[0] == ' ')
		cnt--;
	if (s[s.length()-1] == ' ')
		cnt--;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ')
			cnt++;
	}
	cout << cnt + 1 << '\n';
	return 0;
}