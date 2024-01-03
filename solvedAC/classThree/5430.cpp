#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

/*
    문제 풀이 주의사항
    1. 시간제한 때문에 수열을 진짜 뒤집으면 시간초과가 난다.
    2. deque를 사용해야 편하게 풀 수 있다.
*/

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;

    cin >> t;
    while (t--) 
    {
        string order, str;
        bool isReverse = false, isError = false;
        deque<int> container;
        cin >> order;
        cin >> n;
        cin >> str;
        string s = "";
        for (int i = 0; i < str.length(); i++) {

            if (isdigit(str[i])) 
            {
                s += str[i];
            }
            else 
            {
                if (!s.empty()) 
                {
                    container.push_back(stoi(s));
                    s = "";
                }
            }
        }
        for (auto o : order) 
        {
            if (o == 'R') 
            {
                if (isReverse)
                    isReverse = false;
                else
                    isReverse = true;
            }
            else 
            {
                if (container.empty()) 
                {
                    cout << "error" << '\n';
                    isError = true;
                    break;
                }
                if (isReverse)
                    container.pop_back();
                else
                    container.pop_front();
            }
        }
        if (!isError) 
        {
            cout << '[';
        }
        if (isReverse && !container.empty()) 
        {
            for (auto o = container.rbegin(); o != container.rend(); o++) 
            {
                if (o == container.rend() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }
        else if (!isReverse && !container.empty()) 
        {
            for (auto o = container.begin(); o != container.end(); o++) 
            {
                if (o == container.end() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }
        if (!isError)
            cout << "]\n";

    }
}