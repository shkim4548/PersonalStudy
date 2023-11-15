#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	좌상단을 기준으로 잡고 모두 찾아서 최소값을 찾는다.
*/
int minRepaint(vector<string>& board, int x, int y);

int main() {
	int N, M;
	ci >> n >> m;
	vector<string> board(N);
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int minRepaintCount = 64;
	for (int i = 0; i + 7 < N; i++) {
		for(int j = 0;j+7<M;j++)
			minRepaintCount = min(minRepaintCount, minRepaint(board, i, j))
	}
}