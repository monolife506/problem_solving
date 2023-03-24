#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;

    if (m < n)
    {
        cout << "No" << '\n';
        return;
    }

    if (n % 2 == 0)
    {
        if (m % 2 != 0)
        {
            cout << "No" << '\n';
            return;
        }

        cout << "Yes" << '\n';
        for (int i = 0; i < n - 2; ++i)
            cout << 1 << " ";
        cout << (m - (n - 2)) / 2 << " " << (m - (n - 2)) / 2 << '\n';
    }
    else
    {
        cout << "Yes" << '\n';
        for (int i = 0; i < n - 1; ++i)
            cout << 1 << " ";
        cout << m - (n - 1) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

if n % 2 == 1
1 1 1 1 ... 1 m - (n - 1)
else


*/