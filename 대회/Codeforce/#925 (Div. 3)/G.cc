#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;
ll fac[10000001];

ll pow_mod(ll n, ll r)
{
    if (r == 0)
        return 1;

    ll half = pow_mod(n, r / 2);
    ll ret = (half * half) % MOD;

    if (r % 2 == 1)
        ret = (ret * n) % MOD;

    return ret;
}

ll C(ll n, ll r)
{
    ll ret = fac[n];
    ret = (ret * pow_mod(fac[n - r], MOD - 2)) % MOD;
    ret = (ret * pow_mod(fac[r], MOD - 2)) % MOD;
    return ret;
}

ll H(ll n, ll r) { return C(n + r - 1, r); }

void solve()
{
    ll c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

    if (abs(c1 - c2) >= 2)
    {
        cout << 0 << '\n';
        return;
    }

    if (c1 == 0 && c2 == 0)
    {
        if (c3 != 0 && c4 != 0)
        {
            cout << 0 << '\n';
            return;
        }

        cout << 1 << '\n';
        return;
    }

    ll ans = 0;
    if (abs(c1 - c2) == 0)
    {
        ans += H(c1 + 1, c3) * H(c1, c4) % MOD;
        ans += H(c1, c3) * H(c1 + 1, c4) % MOD;
        ans %= MOD;
    }
    else // abs(c1 - c2) == 1
    {
        ans = H(max(c1, c2), c3) * H(max(c1, c2), c4) % MOD;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fac[0] = 1;
    for (ll i = 1; i <= 10000000; ++i)
        fac[i] = (fac[i - 1] * i) % MOD;

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

11
00
01
10

10 11 01 00 10 11 01

*/