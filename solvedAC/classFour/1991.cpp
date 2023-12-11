#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 27;

// 
pair<int, int> graph[26];

// 

/*
	트리 순회
	- DFS와 비슷한 느낌으로 재귀적으로 구현한다.
*/

// 전위 순회
void preorder(char x)
{
	if (x != '.')
	{
		cout << x;
		preorder(graph[x - 'A'].first);
		preorder(graph[x - 'A'].second);
	}
}

// 중위 순회
void inorder(char x)
{
	if (x != '.')
	{
		inorder(graph[x - 'A'].first);
		cout << x;
		inorder(graph[x - 'A'].second);
	}
}

// 후위 순회
void postorder(char x)
{
	if (x != '.')
	{
		postorder(graph[x - 'A'].first);
		postorder(graph[x - 'A'].second);
		cout << x;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;
		graph[(parent - 'A')].first = left;
		graph[(parent - 'A')].second = right;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';
}