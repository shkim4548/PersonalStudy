#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 각 계산값이 범위를 넘지 않도록 m으로 나눈 나머지를 구하게한다.
int main(void) 
{
	int l;
	long long m  = 1234567891, r = 1;
	long long sum = 0;
	string str;
	//�Է��� ���� �ҹ��ڸ�, ASCII 'a'==97
	cin >> l >> str;

	for (int i = 0; i < str.length(); i++) 
	{
		sum += ((str[i] - 'a' + 1) * r) % m;
		r = (r * 31) % m;
	}
	cout << sum % m << '\n';
	return 0;
}