#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//요세푸스 문제 0
int main(void) {
	int n, k;
	cin >> n >> k;

	queue<int> josephs;

	//입력받은 크기의 큐를 초기화
	for (int i = 1; i <= n; i++)
	{
		josephs.push(i);
		cout << josephs.back() << " ";
	}

	for (int i = 1; i <= josephs.size(); i++)
	{
		
	}
}