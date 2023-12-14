#include <iostream>
#include <vector>
using namespace std;

int n, answer = 0;
vector<int> visited(15, -1);

// 유망한 조건을 판단한다, cnt는 퀸이 배치된 행번호
bool Check(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		// 배치했던 퀸들과 현재 배치하려는 퀸이 서로 공격할 수 있다면 return 0
		// 세로축 판단 : 현재 배치한 퀸의 열 == 배치했던 퀸의열
		// 대각축 판단 : 현재 배치한 퀸의 행 - 배치했던 퀸의 행 == 절대값 
		if(visited[cnt] == visited[i] || cnt - i == abs(visited[cnt]- visited[i]))
			return false;
	}

	// 현재 퀸을 배치할 수 있다면 return 1(true)
	return true;
}

void nQueen(int cnt)
{
	if (cnt == n)
	{
		// 답이 되는 부분을 ++
		answer++;
	}
	
	else
	{
		for (int i = 0; i < n; i++)
		{
			visited[cnt] = i;
			if (Check(cnt))
				nQueen(cnt + 1);
		}
	}
}

int main(void)
{
	cin >> n;
	nQueen(0);
	cout << answer << '\n';
}