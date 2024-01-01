#include <iostream>
using namespace std;

int main(void) {
	int n, count = 0;
	cin >> n;
	for (int i = n; i >= 0; i--) {
		if (i == 0)
			continue;
		if (i % 125 == 0)
			count += 3;

		else if (i % 25 == 0)
			count += 2;

		else if (i % 5 == 0)
			count += 1;
		
	}
	cout << count;
}