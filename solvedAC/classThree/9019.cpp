#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10001;
vector<bool> visited(MAX, false);
int a, b;

void bfs()
{
	queue<pair<int, string>> q;
	q.push(make_pair(a, ""));
	visited[a] = true;
	while (!q.empty())
	{
		int currentNum = q.front().first;
		string command = q.front().second;
		q.pop();


		if (currentNum == b)
		{
			cout << command << '\n';
			return;
		}
		// 여기서부터 각 연산을 처리해준다.
		
		int D, S, L, R, tmp;
		
		D = (currentNum * 2) % 10000;
		if (!visited[D])
		{
			visited[D] = true;
			q.push(make_pair(D, command + "D"));
		}

		S = (currentNum - 1 < 0 ? 9999 : currentNum - 1);
		if (!visited[S])
		{
			visited[S] = true;
			q.push(make_pair(S, command + "S"));
		}

		L = (currentNum % 1000) * 10 + (currentNum / 1000);
		if (!visited[L])
		{
			visited[L] = true;
			q.push(make_pair(L, command + "L"));
		}

		R = currentNum / 10 + (currentNum % 10) * 1000;
		if (!visited[R])
		{
			visited[R] = true;
			q.push(make_pair(R, command + "R"));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		// 탐색 전에 항상 초기화를 다시 해줘야한다
		fill(visited.begin(), visited.end(), false);
		bfs();
	}
	return 0;
}