#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    stack<int> s;
    vector<char> result;

    // count는 1부터 시작해서 일단 stack에 넣는다
    int count = 1;
    for (int i = 0; i < n; ++i) {
        // stack이 비었거나, stack의 top이 입력받은 수열의 0번과 다르다
        while (s.empty() || s.top() != sequence[i]) {
            if (count > n) {
                cout << "NO" << '\n';
                return 0;
            }
            // 끝낼 상황이 아니라면 stack에 count를 채운다.
            s.push(count);
            result.push_back('+');
            count++;
        }

        // stack의 top을 보고 맞으면 답 벡터에 -를 채운다
        if (s.top() == sequence[i]) {
            s.pop();
            result.push_back('-');
        }
    }

    for (char c : result)
        cout << c << '\n';

    return 0;
}
