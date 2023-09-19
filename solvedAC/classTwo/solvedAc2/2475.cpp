#include <iostream>
using namespace std;

int main()
{
    int a;
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> a;
        sum += a * a;
        cout << "a : " << a << ", " << "sum : " << sum << endl;
    }
    cout << sum % 10 << endl;
    return 0;
}