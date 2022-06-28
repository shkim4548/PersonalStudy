#include<iostream>
#include<math.h>
using namespace std;

int main(void) {
	int min, max, i, j;
	cin >> min;
	cin >> max;

	for (i = min; i <= sqrt(max); i++) {
		if (i == 0 || i == 1)
			continue;
		for (j = 2; j <= i; j++) {
			if (i % j == 0)
				break;
		}
		//endl은 시간초과가 무조건 뜬다.
		if (i == j)
			cout << i << '\n';
	}
	return 0;
}
//현재 시간초과 발생함