#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string a, string b);

int main(void) {
	int n;
	string a;
	cin >> n;
	//리스트가 선후 입출력 모두 유리함 중간 값 제거시 시간 복잡도는 O(1), 정렬은 list가 더 편함
	//중복제거에도 list가 유리함
	vector<string> str;
	for (int i = 0; i < n; i++) {
		cin >> a;
		str.push_back(a);
	}

	//custom sorting 적용
	sort(str.begin(), str.end(), compare);
	//vector 중복제거
	str.erase(unique(str.begin(), str.end()), str.end());
	//cout << '\n';

	for (int i = 0; i < str.size(); i++) {
		cout<<str[i]<<'\n';
	}

	return 0;
}

//custom sorting을 위한 사용자 정의 함수 정의
//sort를 두번 실행하면
bool compare(string a, string b) {
	if(a.size()!=b.size())
		return a.size() < b.size();
	else 
		return a < b;
		//string은 전체 단어 하나가 아스키에 비례하는 값하나로 바뀜
}