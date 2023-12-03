#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 8;

void dfs(int n, int m, vector<int>& numbers, vector<int>& permutation, vector<bool>& visited)
{
    if (permutation.size() == m)
    {
        for (int num : permutation)
        {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            permutation.push_back(numbers[i]);
            dfs(n, m, numbers, permutation, visited);
            visited[i] = false; // 백트래킹: 이전 상태로 돌아간다.
            permutation.pop_back();

            // 중복된 숫자 건너뛰기
            while (i + 1 < n && numbers[i] == numbers[i + 1])
            {
                i++;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    vector<int> permutation;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    dfs(n, m, numbers, permutation, visited);

    return 0;
}
