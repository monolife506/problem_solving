#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (abs(a - 1) < abs(b - c) + abs(c - 1))
            cout << 1 << '\n';
        else if (abs(a - 1) > abs(b - c) + abs(c - 1))
            cout << 2 << '\n';
        else
            cout << 3 << '\n';
    }
}