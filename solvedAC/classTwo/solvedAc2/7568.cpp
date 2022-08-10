#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool custonSort(pair<int, int> param1, pair<int, int> param2) {
	
}

int main(void) {
	int n, tall, weight, rank;
	pair<int, int> input;
	vector<pair<int, int>> dungChi;

	//모두 입력 받고
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input.first >> input.second;
		dungChi.push_back(make_pair(input.first, input.second));
	}

	sort(dungChi.begin(), dungChi.end());
	for(int i=0;i<)
}