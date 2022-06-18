#include"iostream"
#include"string"
using namespace std;

int main() {
	int n;
	string str;
	int score = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		//이제 여기서 누적해서 더해야한다.
		if (str[i - 1] != null && str[i - 1] == 'O') {
			score++;
		}
		else {
			score = 0;
		}
		cout << score;
	}
}