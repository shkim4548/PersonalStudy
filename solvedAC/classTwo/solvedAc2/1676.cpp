#include "iostream"
#include "vector"

long long factorial(int num) {
	long long result = 1;
	for (int i = 1; i <= num; ++i) {
		result = result * i;
	}
	std::cout << result << std::endl;
	return result;
}

int main(void)
{
	int n, count = 0;
	std::cin >> n;
	long long res = factorial(n);
	std::cout << res << std::endl;
	while(true) {
		if (res / 10 <= 0)
			break;
		if (res % 10 == 0) {
			std::cout << res << std::endl;
			count++;
		}
		res /= 10;
		std::cout << res << std::endl;
	}
	std::cout << count;
}