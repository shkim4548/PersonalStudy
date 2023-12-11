#include <iostream>
#include <vector>
using namespace std;

void difference_sequence(int floor, int rooms) 
{
	int sum = 0;
	for (int i = 0; i < floor; i++)
	{
		for (int j = 1; j <= rooms; j++)
		{

		}
	}
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, floor, rooms;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> floor >> rooms;
		difference_sequence(floor, rooms);
	}
	return 0;
}