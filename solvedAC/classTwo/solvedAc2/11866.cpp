#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//�似Ǫ�� ���� 0
int main(void) {
	int n, k;
	cin >> n >> k;

	queue<int> josephs;

	//�Է¹��� ũ���� ť�� �ʱ�ȭ
	for (int i = 1; i <= n; i++)
	{
		josephs.push(i);
		cout << josephs.back() << " ";
	}

	for (int i = 1; i <= josephs.size(); i++)
	{
		
	}
}