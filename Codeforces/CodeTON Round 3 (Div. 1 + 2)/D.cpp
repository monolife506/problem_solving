#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

vector<ll> factorization(ll n)
{
    vector<ll> ret;
    if (n % 2 == 0)
    {
        ret.push_back(2);
        while (n % 2 == 0)
            n /= 2;
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i != 0)
            continue;

        ret.push_back(i);
        while (n % i == 0)
            n /= i;
    }

    if (n > 2)
        ret.push_back(n);

    return ret;
}

ll get_non_coprime_cnt(vector<ll> &p, int i, ll val, ll m)
{
    if (i == p.size() || val * p[i] > m)
        return 0;

    ll ret = (m / p[i]) / val;
    ret += get_non_coprime_cnt(p, i + 1, val, m);
    ret -= get_non_coprime_cnt(p, i + 1, val * p[i], m);
    return ret;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll ans = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] % a[i] != 0)
        {
            cout << 0 << '\n';
            return;
        }

        vector<ll> fac = factorization(a[i - 1] / a[i]);
        ans *= (m / a[i]) - get_non_coprime_cnt(fac, 0, 1, m / a[i]);
        ans %= MOD;
    }

    cout << ans << '\n';
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

gcd(a[i - 1], b[i]) = a[i]
gcd(a[i - 1], k * a[i]) = a[i]
gcd(a[i - 1] / a[i], k) = 1

1 <= k <= m / a[i]

*/