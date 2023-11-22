#include <iostream>
#include <vector>
using namespace std;

/*
	��������
	- ����Ž���� �̿��Ͽ� ó���Ѵ�.
	- �� �о� ��ü�� ���ȣ��� ������ ������ ���.
	- ���ð� �Ǵ� �Ʒ��� �ڵ带 �����Ͽ� 2���� ������ ó���Ѵ�.
		- ����ó���� �̱� ������� �ѵ� �ӵ��� ū ������ ������?
*/
const int MAX = 129;
vector<vector<int>> paper(MAX);
int n, blue = 0, white = 0;

// �����ؼ� ���پ� �־�����
void binarySearch(int row, int col, vector<vector<int>>& vec, int size) {
	int midRow = row / 2;
	int midCol = col / 2;

	// �Ѱ��� ������ ��� ���� �����ΰ�?
	for (int i = midRow; i < midRow + n; i++) {
		for (int j = midCol; j < midCol+ n; j++) {
			if (vec[i][j] == vec[i + 1][j + 1])
			{
				if (vec[i][j] == 1)
					blue++;
				else
					white++;
			}
			else 
			{

			}
		}
	}

	// ���̻� ���� �� �����鼭 ���� ������ -1 ��ȯ
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int input;

	// ���� �Է¹���
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			paper[i].push_back(input);
		}
	}

	binarySearch(0, n, paper);
	// ����Ž���� �����Ѵ�
	cout << blue << ' ' << white << '\n';
}