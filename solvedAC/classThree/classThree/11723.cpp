#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) 
{
	int n, bitmask = 20, input;
	string calculate;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> calculate;
		cin >> input;
		if (calculate == "add")
		{
			bitmask << input;
		}
		else if (calculate == "remove")
		{

		}
		else if (calculate == "check")
		{

		}
		else if (calculate == "toggle")
		{

		}
		else if (calculate == "all")
		{

		}
		else if (calculate == "empty")
		{

		}
	}
}