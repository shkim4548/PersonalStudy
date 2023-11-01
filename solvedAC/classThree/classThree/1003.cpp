#include <iostream>
#include <vector>
using namespace std;

/*
    동적계획법
    메모이제이션을 활용하여 풀이한 문제
    입력이 비동기처리가 된다해도 온라인 컴파일러는 느려서 미리 계산하는게 빠르다
*/

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    int memoization[41] = { 0,1, 1 };
    cin >> n;
    // 메모이제이션을 효율적으로 구성하기 위해서 함수를 굳이 분리하지 않는다
    for (int i = 3; i < 41; i++) {
        memoization[i] = memoization[i - 1] + memoization[i - 2];
    }

    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 0)
            cout << 1 << ' ' << 0 << '\n';
        else if (t == 1)
            cout << 0 << ' ' << 1 << '\n';
        else
            cout << memoization[t - 1] << ' ' << memoization[t] << '\n';
    }

    return 0;
}