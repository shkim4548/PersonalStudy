#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
	���� ��ȣ ���̱�
*/

// �������� ����
const int MAX = 26;
int GRAPH[MAX][MAX] = { 0 };
int DY[4] = { 1, -1, 0, 0 };
int DX[4] = { 0,0, 1,-1 };
int VISITED[MAX][MAX] = { 0 };

int N, M;
int group = 1;

// DFS �Լ�
void DFS(int y, int x) {
	// �����¿� Ž��
	for (int i = 0; i < 4; i++) {
		int ny = y + DY[i];
		int nx = x + DX[i];
		// ������ �ǹ� �� ī��Ʈ
		

		// �迭�� �ε����� �Ѿ�� �ʵ��� üũ�Ѵ�
		if (ny < 0 || nx < 0 || ny >= MAX || nx >= MAX)
			continue;

		// Ž������ ���� ������ üũ�Ͽ� Ž���Ѵ�
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

	sort(total.begin(), total.end());

	cout << total.size() << '\n';
	// 1�� �ٿ� �� �������� ���� ���;� �ϱ� ������ ��ºο� ����θ� �и�
	for (int i = 0; i < total.size(); i++) {
		cout << total[i] << '\n';
	}
	
	return 0;
}