#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>
using namespace std;

/*
	포켓몬 마스터 이다솜 문제
	- isdigit -> int인지 판단하는 함수
	- stoi -> string to int
*/

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	unordered_map<int, string> map;
	unordered_map<string, int> mapR;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		map.insert(make_pair(i, input));
		mapR.insert(make_pair(input, i));
	}

	for (int i = 0; i < M; i++) 
	{
		string input;
		cin >> input;
		if (isdigit(input[0]) != 0) {
			cout << map[stoi(input) - 1];
		}
		else
			cout << mapR[input] + 1;

		cout << '\n';
	}
	return 0;
}