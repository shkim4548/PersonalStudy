#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string pelindrom;
	bool ans = true;
	while (1) {
		cin >> pelindrom;
		if (pelindrom == "0") return 0;
		//짝수면 검사의 필요가 없다.
		if (pelindrom.size() % 2 == 0) {
			ans = false;
			//cout << pelindrom.size() << '\n';
		}
		//펠린드롬수 여부 검사
		for (int i = 0; i < pelindrom.size(); i++) {
			//cout << pelindrom[i] << " " << pelindrom[pelindrom.size() - i - 1] << '\n';
			if (pelindrom[i] != pelindrom[pelindrom.size() - i - 1]) {
				ans = false;
				break;
				//if (i == pelindrom.size() / 2 + 1) continue;
			}
			else {
				ans = true;
				//if (i == pelindrom.size() / 2 + 1) continue;
			}
		}
		if (ans == true) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}