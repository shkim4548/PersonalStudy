#include<iostream>
using namespace std;

// 0.15�� ������ �ݺ����� ����ؼ��� �ȉ´�.
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, V, dis = 0, cnt = 1;
	cin >> A >> B >> V;

	/*
	while (1) {
		V -= A;
		if (V <= 0) {
			cout << cnt << '\n';
			break;
		}
		V += B;
		cnt++;
	}
	*/
	dis = (V - B - 1) / (A - B) + 1;
	cout << dis << '\n';
	return 0;
}