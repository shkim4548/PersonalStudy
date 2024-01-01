#include <iostream>
#include <cmath>
using namespace std;

/*------------------------
	에라토스테네스의 체
--------------------------*/


int main(void) {
	bool arr[1000001] = { false };

	int start, end;
	cin >> start >> end;

	arr[0] = arr[1] = true;
	for (int i = 2; i * i <= end; ++i)	// n의 제곱근까지만 지운다
	{	
		if (arr[i]) continue;	// i가 이미 true면 continue -> 이미 지워진 수라는 뜻
		else 
		{
			for (int j = 2; j * i <= end; ++j)	// i의 배수를 지운다
			{
				arr[i * j] = true;
			}
		}
	}

	for (int i = start; i <= end; i++)	// false인 내용만 출력한다.
	{
		if (!arr[i])
			cout << i << '\n';
	}

	return 0;
}