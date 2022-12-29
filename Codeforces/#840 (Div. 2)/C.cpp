#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll max_a = 0, max_idx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (max_a < a[i])
        {
            max_a = a[i];
            max_idx = i;
        }
    }

    if (n == 2)
    {
        cout << max(a[0] + a[1], abs(a[0] - a[1]) * 2) << '\n';
    }
    else if (n == 3)
    {
        if (max_idx == 0 || max_idx == 2)
        {
            cout << max_a * n << '\n';
        }
        else
        {
            ll ans = a[0] + a[1] + a[2];
            ans = max(ans, a[0] * 3);
            ans = max(ans, a[2] * 3);
            ans = max(ans, abs(a[0] - a[1]) * 3);
            ans = max(ans, abs(a[1] - a[2]) * 3);
            cout << ans << '\n';
        }
    }
    else // n >= 4
    {
        cout << max_a * n << '\n';
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

1 10 2

9 9 2

9 7 7



*/