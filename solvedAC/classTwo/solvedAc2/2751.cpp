#include<iostream>
using namespace std;

//우선 버블 정렬로 시행하고, 정렬 후 앞에 같은게 있으면 뒤에걸 삭제
int main(void) {
	int n, t;
	int a[100];
	cin >> n;
	//여기서 배열 입력 받고
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

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
}