#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<long long, long long> fibo;
int DIV = 10000'00007;
/*
	분할정복을 이용한 거듭제곱
	- 점화식
	- F[2n] = F[n]x(2F[n-1] + F[n])
	- F[2n+1] = F[n+1]^2 + F[n]^2
*/

long long Fibonacci(long long n)
{
	if (n == 0)
		return 0;
	if (n <= 2)
		return 1;

	if (fibo.count(n) > 0)
		return fibo[n];

	// 분할 정복 : 짝수인 경우
	if (n % 2 == 0)
	{
		long long m = n / 2;
		long long temp1 = Fibonacci(m - 1);
		long long temp2 = Fibonacci(m);
		fibo[n] = ((2 * temp1 + temp2) * temp2) % DIV;
		return fibo[n];
	}

	long long m = (n + 1) / 2;
	long long temp1 = Fibonacci(m);
	long long temp2 = Fibonacci(m - 1);
	fibo[n] = (temp1 * temp1 + temp2 * temp2) % DIV;
	return fibo[n];
}


int main(void)
{
	long long n;
	cin >> n;
	cout << Fibonacci(n);

	return 0;
}