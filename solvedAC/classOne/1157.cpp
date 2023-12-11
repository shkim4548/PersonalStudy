#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<char, int> a, pair<char, int> b)
{
	return a.second > b.second;
}

int main(void)
{
	int charCount = 0;
	string input;
	vector<pair<char, int>> counter(26);
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		// 모두 대문자로 변환하여 비교한다
		if (input[i] >= 97 && input[i] <= 122)
			input[i] = input[i] - 32;

		// 정렬되어있으므로 vector에 때려박고 제일 긴거 출력
		counter[i].second++;
	}

	sort(counter.begin(), counter.end(), compare);
	cout << counter[0].first << '\n';
	return 0;
}