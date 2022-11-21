#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if (a == b)
    {
        cout << 0 << '\n';
    }
    else if (abs(a - b) >= x)
    {
        cout << 1 << '\n';
    }
    else if (a - x >= l && b - x >= l)
    {
        cout << 2 << '\n';
    }
    else if (a + x <= r && b + x <= r)
    {
        cout << 2 << '\n';
    }
    else if (a - x >= l && b + x <= r)
    {
        cout << 3 << '\n';
    }
    else if (a + x <= r && b - x >= l)
    {
        cout << 3 << '\n';
    }
    else
    {
        cout << -1 << '\n';
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