#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    if (T % 10 != 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << T / 300 << " ";
        T %= 300;
        cout << T / 60 << " ";
        T %= 60;
        cout << T / 10 << '\n';
    }
}