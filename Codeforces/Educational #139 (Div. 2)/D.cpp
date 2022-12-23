#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll spf[10000001];

vector<ll> factorization(ll num)
{
    vector<ll> ret;
    while (num != 1)
    {
        ret.push_back(spf[num]);
        num /= spf[num];
    }

    return ret;
}

void solve()
{
    ll x, y;
    cin >> x >> y;

    if (gcd(x, y) != 1)
    {
        cout << 0 << '\n';
    }
    else if (y - x == 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        vector<ll> f = factorization(y - x);

        ll ans = (y - x) - (y % (y - x));
        for (ll num : f)
            ans = min(ans, num - (y % num));

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (ll i = 2; i <= 10000000; ++i)
        spf[i] = i;
    for (ll i = 2; i * i <= 10000000; i++)
    {
        if (spf[i] != i)
            continue;
        for (ll j = i * i; j <= 10000000; j += i)
            spf[j] = i;
    }

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

gcd(10009, 20000) = 1
9991 = 97 * 103

13 37, 2^3 * 3

22 37
mod 3 = 1
mod 5 = 2

*/