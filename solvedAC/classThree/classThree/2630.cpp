#include <iostream>
#include <vector>
using namespace std;

/*
	분할정복
	- 이진탐색을 이용하여 처리한다.
	- 이 분야 자체가 재귀호출과 굉장히 관련이 깊다.
	- 예시가 되는 아래의 코드를 변형하여 2차원 분할을 처리한다.
		- 동기처리에 싱글 스레드긴 한데 속도에 큰 무리는 없을듯?
*/
const int MAX = 129;
vector<vector<int>> paper(MAX);
int n, blue = 0, white = 0;

// 분해해서 한줄씩 넣어주자
void binarySearch(int row, int col, vector<vector<int>>& vec, int size) {
	int midRow = row / 2;
	int midCol = col / 2;

	// 한개의 영역이 모두 같은 숫자인가?
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

	// 더이상 나눌 수 없으면서 값이 없으면 -1 반환
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int input;

	// 종이 입력받음
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			paper[i].push_back(input);
		}
	}

	binarySearch(0, n, paper);
	// 이진탐색을 실행한다
	cout << blue << ' ' << white << '\n';
}