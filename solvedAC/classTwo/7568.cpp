#include<iostream>
using namespace std;

const int MAX_PERSONALS = 50;

struct Person
{
	int height;
	int weight;
	int rank = 1;
};

int main(void) 
{
	Person person[MAX_PERSONALS];
	int size, rank;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> person[i].height >> person[i].weight;
		//cout << person[i].height << '\n' << person[i].weight << '\n';
	}
	for (int i = 0; i < size; i++)
	{
		int j = 0;
		while (j < size)
		{
			if (person[i].height < person[j].height && person[i].weight < person[j].weight)
				person[i].rank++;
			j++;
		}
	}

	for (int i = 0; i < size; i++)
		cout << person[i].rank << ' ';
}