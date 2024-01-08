#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibo[1001] = { 0 };

int Fibonacci(int x)
{
	fibo[1] = 1;
	fibo[2] = 3;

	if (fibo[x])
	{
		return fibo[x];
	}

	// 점화식을 알아내는게 중요한 수학문제였다
	return	fibo[x] = (Fibonacci(x - 1) % 10007 +2 * Fibonacci(x - 2)) % 10007;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	cout << Fibonacci(n) << '\n';
	return 0;
}