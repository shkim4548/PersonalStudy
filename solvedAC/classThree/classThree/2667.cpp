#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	단지 번호 붙이기
*/

// 전역변수 영역
const int MAX = 26;
int GRAPH[MAX][MAX] = { 0 };
int DY[4] = { 1, -1, 0, 0 };
int DX[4] = { 0,0, 1,-1 };
int VISITED[MAX][MAX] = { 0 };

int N, M;
int group = 1;

// DFS 함수
void DFS(int y, int x) {
	// 상하좌우 탐색
	for (int i = 0; i < 4; i++) {
		int ny = y + DY[i];
		int nx = x + DX[i];
		// 단지당 건물 수 카운트
		

		// 배열의 인덱스가 넘어가지 않도록 체크한다
		if (ny < 0 || nx < 0 || ny >= MAX || nx >= MAX)
			continue;

		// 탐색하지 않은 영역을 체크하여 탐색한다
		if (GRAPH[ny][nx] && !VISITED[ny][nx]) {
			VISITED[ny][nx]++;
			group++;
			DFS(ny, nx);
		}
	}
}

int main(void) {
	vector<int> total;
	string input;
	int row, res = 0;
	cin >> row;
	for (int i = 0; i < row; i++) {
		cin >> input;
		for (int j = 0; j < row; j++) {
			int tmp = input[j] - '0';
			GRAPH[i][j] = tmp;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (GRAPH[i][j] && !VISITED[i][j]) {
				VISITED[i][j]++;
				DFS(i, j);
				total.push_back(group);
				group = 1;
			}
		}
	}

	cout << total.size() << '\n';
	// 1번 줄에 총 단지수가 먼저 나와야 하기 때문에 출력부와 연산부를 분리
	for (int i = 0; i < total.size(); i++) {
		cout << total[i] << '\n';
	}
	
	return 0;
}