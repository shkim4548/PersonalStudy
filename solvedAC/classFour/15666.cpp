#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSequences(int start, int n, int m, vector<int>& numbers, vector<int>& sequence, vector<bool>& visited) 
{
    if (m == 0) 
    {
        for (int num : sequence) 
        {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    int last = 0;

    for (int i = start; i < n; i++) 
    {
        if (numbers[i] != last)
        {
            sequence.push_back(numbers[i]);
            last = numbers[i];
            generateSequences(i, n, m - 1, numbers, sequence, visited);
            sequence.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) 
    {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    vector<int> sequence;
    generateSequences(0, n, m, numbers, sequence, visited);

    return 0;
}
