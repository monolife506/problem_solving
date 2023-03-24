#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    if (n % 2 == 0)
    {
        for (int i = n / 2; i >= 1; --i)
            cout << n - i << " ";
        for (int i = 1; i <= n / 2; ++i)
            cout << n + i << " ";
    }
    else
    {
        for (int i = n; i >= n / 2 + 2; --i)
            cout << n * 4 - i << " ";

        cout << n * 4 << " ";

        for (int i = n / 2 + 2; i <= n; ++i)
            cout << n * 4 + i << " ";
    }

    cout << '\n';
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

n = 9

36 - 9, 36 + 9
36 - 8, 36 + 8
36 - 7, 36 + 7
36 - 6, 36 + 6

n = 7

21 - 7
21 - 6
21 - 5

*/