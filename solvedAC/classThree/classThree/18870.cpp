#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	좌표압축
	- 수의 범위가 매우 큰 상태에서 수의 값과 상관 없이 숫자간의 대소관계만 알면 될때 사용

	단계별 풀이
	- 오름차순 정렬
	- 중복 요소를 제거한다
	- 인풋 배열요소
*/
int arr[1000001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> original;
	for (int i = 0; i < n; i++) 
	{
		int b;
		cin >> arr[i];
		original.push_back(arr[i]);
	}

	sort(original.begin(), original.end());
	original.erase(unique(original.begin(), original.end()), original.end());
	for (int i = 0; i < n; i++)
	{
		// 원래 배열의 원소가 새 배열의 어느 위치로 압축되었는지 출력
		int idx = lower_bound(original.begin(), original.end(), arr[i]) - original.begin();
		cout << idx << ' ';
	}
	return 0;
}