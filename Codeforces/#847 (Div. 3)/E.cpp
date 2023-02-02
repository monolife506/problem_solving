#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    ll x;
    cin >> x;

    if (x % 2 == 1)
    {
        cout << -1 << '\n';
        return;
    }

    ll a = x, b = 0;
    for (int i = 1; i <= 32; ++i)
    {
        if (!(x & (1 << i)))
            continue;
        if ((1 << i) & (x << 1))
        {
            cout << -1 << '\n';
            return;
        }

        a += (1 << (i - 1));
        b += (1 << (i - 1));
    }

    cout << a << " " << b << '\n';
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

5
101
4

18
10010

100100
16 8 2

10
1010
8 2

*/