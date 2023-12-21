#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	이진 검색 트리
	- 이진 검색 트리 조건
		1. 노드위 좌측 서브 트리에 있는 모든 노드의 키는 노드의 키보다 작다
		2. 노드의 우측 서브 트리에 있는 모든 노드의 키는 노드의 키보다 큳
		3. 좌, 우측 서브트리도 이진 검색 트리이다.

	- 이진트리와 분할 정복
		1. 우측 서브트리와 좌측 서브트리를 분할정복의 개념을 이용하여 풀면 이진 트리 공략 성공
*/
int graph[10001];
int i;

// 결과는 후위 순회로
void postorder(int start, int end)
{
	if (start >= end)
		return;

	for (i = start + 1; i < end; i++)
	{
		if (graph[start] < graph[i])
			break;
	}

	postorder(start + 1, i);
	postorder(i, end);
	cout << graph[start] << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0, x;

	while (true)
	{
		cin >> x;
		if (cin.eof())
			break;
		else
			graph[n++] = x;
	}
	postorder(0, n);

	return 0;
}