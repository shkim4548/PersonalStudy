#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];
vector<bool> visited(MAX);
vector<int> answer(MAX);

/*
	풀이 방식
	- 탐색을 진행하면서 부모노드를 세팅해줘야한다.

	- 참고자료
	https://iridescent-zeal.tistory.com/38
*/

void Bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!visited[y])
			{
				// 자식노드가 방문하지 않았다면 이제 접근한다
				// 새 노드에 접근하기 전에 미리 부모노드를 따둔다.
				answer[y] = x;
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main(void)
{
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	Bfs(1);

	for (int i = 2; i <= n; i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}