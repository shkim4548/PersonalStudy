#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�켱 ���� ���ķ� �����ϰ�, ���� �� �տ� ������ ������ �ڿ��� ����
int main(void) {
	int n, t;
	//int a[100];
	vector<int> numbers;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		numbers.push_back(t);
	}
	sort(numbers.begin(), numbers.end());
	//���� ������ �̿��� �� -> �ð��ʰ�
	/*
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			//���� ���� ����
			if (a[i] > a[j]) {
				//�ߺ��˻�
				if (a[i] == a[j]) {
					// �տ��Ŷ� �ڿ��Ŷ� ������ �ڿ��� �տ��ɷ� ������.
					a[j] = a[i];
				}
				t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
	*/
	for (int i = 0; i < n; i++)
		cout << numbers[i] << '\n';

	return 0;
}