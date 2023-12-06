#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	비트 마스킹
	- 패킷 조립등을 위해 자주 사용하는 기법이니 반드시 숙지할 것
	- https://gyoogle.dev/blog/algorithm/BitMask.html
*/

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int bitmask = 0;
	int n, input;
	string calculate;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> calculate;
		if (calculate == "add")
		{
			cin >> input;
			// input 번째 자리수를 1로 채운다
			bitmask |= (1 << input);
		}
		else if (calculate == "remove")
		{
			cin >> input;
			// input 번째 자리수를 반전하여 비트곱한다 -> 반드시 0이 된다
			bitmask &= ~(1 << input);
		}
		else if (calculate == "check")
		{
			cin >> input;
			// 해당 위치의 비트마스크가 true인지를 확인한다.
			if (bitmask & (1 << input))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (calculate == "toggle")
		{
			cin >> input;
			bitmask ^= (1 << input);
		}
		else if (calculate == "all")
		{
			//cin >> input;
			// -1을 이용해서 전부 뒤집어버린다.
			bitmask = (1 << 21) - 1;
		}
		else if (calculate == "empty")
		{
			//cin >> input;
			bitmask = 0;
		}
	}
}