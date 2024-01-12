#include <iostream>
#include <vector>
using namespace std;

int fibo[1001] = { 0 };

int Fibonacci(int x)
{
	fibo[1] = 1;
	fibo[2] = 2;
	/*if (x <= 2)
	{
		return 1;
	}*/

	if(fibo[x] != 0)
	{
		// �̹� ����� �ؼ� ���� ������ �ִ� ���
		return fibo[x] % 10007;
	}

	else
	{
		// ���� ������ ���� �ʴٸ� ���� ��� �� return
		fibo[x] = Fibonacci(x - 1) + Fibonacci(x - 2);
		return fibo[x] % 10007;
	}
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