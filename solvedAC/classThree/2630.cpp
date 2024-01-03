#include <iostream>
#include <vector>
using namespace std;

/*
	
*/
const int MAX = 129;
vector<vector<int>> paper(MAX);
int n, blue = 0, white = 0;

void binarySearch(int row, int col, int size) {
	bool flag = true;
	int tmp = paper[row][col];
	for (int i = row; i < row + size; i++) 
	{
		for (int j = col; j < col + size; j++) 
		{
			if (tmp != paper[i][j]) 
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
	}

	// break가 되지 않고 진행될 때
	if (flag != false) {
		if (tmp == 0)
			white++;
		else if (tmp == 1)
			blue++;
	}

	// break가 되었을 때
	else if (flag == false) {
		binarySearch(row, col, size / 2);
		binarySearch(row + size / 2, col, size / 2);
		binarySearch(row, col + size / 2, size / 2);
		binarySearch(row + size / 2, col + size / 2, size / 2);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int input;
	// 그래프를 입력받는다.
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			paper[i].push_back(input);
		}
	}

	binarySearch(0, 0, n);
	cout << white << '\n' << blue << '\n';
}