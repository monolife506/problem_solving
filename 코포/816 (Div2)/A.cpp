#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << 0 << '\n';
        else
            cout << min(2 * (m - 1) + (n - 1) + 1, 2 * (n - 1) + (m - 1) + 1) << '\n';
    }
}