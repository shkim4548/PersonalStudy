#include <iostream>
#include <vector>
using namespace std;

/*
	곱셈문제
	- (A^B)%C를 구해라
	- 분할 정복을 이용한 거듭제곱 계산
*/

int involution(long long base, long long exponent, long long mod) 
{

	// 탈출 조건
	if (exponent == 1)
		return base % mod;
	else if (base == 0)
		return 1;

	long long newBase;

	// 거듭제곱을 실행하는 부분
	// 짝수인 경우
	if (exponent % 2 == 0) {
		newBase = involution(base, exponent / 2, mod) % mod;
		return newBase * newBase % mod;
	}
	// 홀수인 경우
	else 
	{
		newBase = involution(base, (exponent - 1) / 2, mod) % mod;
		return (newBase * newBase) % mod * base % mod;
	}
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	cout << involution(a, b, c) << '\n';
}