#include<iostream>
using namespace std;

//#define arrSize 1000000000

//���� 40020 ����Ʈ ��� �ذ��� ���� ���������� ����(visual c++ �����Ϸ� ���)
int cnt[10001] = { 0 };

int main(void) {
	//�迭�� �������� ����Ѵ�.
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cnt[input]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}