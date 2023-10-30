#include <iostream>
#include <vector>
using namespace std;

/*
    동적계획법
    메모이제이션을 활용하여 풀이한 문제
*/

int cnt0 = 0, cnt1 = 0;
vector<int> memoization;

int fibonacci(int x) {
    //cout << "init fibonacci" << '\n';
    if (x == 0) {
        cnt0++;
        return 0;
    }
    else if (x == 1) {
        cnt1++;
        return 1;
    }
    else {
        return memoization[x] = fibonacci(x - 1) + fibonacci(x - 2);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        memoization.clear();
        memoization.resize(t + 1, 0);
        fibonacci(t);
        cout << cnt0 << ' ' << cnt1 << '\n';
        cnt0 = 0;
        cnt1 = 0;
    }
}