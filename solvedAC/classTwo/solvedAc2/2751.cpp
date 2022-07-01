#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//우선 버블 정렬로 시행하고, 정렬 후 앞에 같은게 있으면 뒤에걸 삭제
int main(void) {
	int n, t;
	//int a[100];
	vector<int> numbers;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		numbers.push_back(t);
	}
	sort(numbers.begin(), numbers.end());
	//버블 정렬을 이용한 모델 -> 시간초과
	/*
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			//버블 정렬 실행
			if (a[i] > a[j]) {
				//중복검사
				if (a[i] == a[j]) {
					// 앞에거랑 뒤에거랑 같으면 뒤에걸 앞에걸로 덮어씌운다.
					a[j] = a[i];
				}
				t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
	*/
	for (int i = 0; i < n; i++)
		cout << numbers[i] << '\n';

	return 0;
}