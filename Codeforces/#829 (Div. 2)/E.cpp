#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;

ll pow_mod(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll half = pow_mod(a, b / 2);
    ll ret = (half * half) % MOD;
    return (b % 2 == 0) ? ret : (ret * a) % MOD;
}

void solve()
{
    ll n;
    cin >> n;

    vector<int> a(n);
    int cnt = 0, icnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 0)
            ++cnt;
    }
    for (int i = 0; i < cnt; ++i)
    {
        if (a[i] != 0)
            ++icnt;
    }

    vector<pll> cache(n + 1);
    cache[0] = {0, 1};
    for (ll i = 1; i <= icnt; ++i)
    {
        cache[i].first = ((cache[i - 1].first * ((i * i * 2) % MOD)) % MOD) + ((((n * (n - 1)) % MOD) * cache[i - 1].second) % MOD);
        cache[i].first %= MOD;
        cache[i].second = cache[i - 1].second * ((i * i * 2) % MOD);
        cache[i].second %= MOD;
    }

    cout << (cache[icnt].first * pow_mod(cache[icnt].second, MOD - 2)) % MOD << '\n';
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

cache[i] = p * cache[i - 1] + (1 - p) * cache[i] + 1
p * cache[i] = p * cache[i - 1] + 1
cache[i] = cache[i - 1] + (1 / p)

cache[0] = 0
cache[1] = n * (n - 1) / 2
cache[2] = n * (n - 1) / 2 + n * (n - 1) / 8
cache[3] = n * (n - 1) / 2 + n * (n - 1) / 8 + n * (n - 1) / 18 ...
         = n * (n - 1) * (1 / 2) * (1 * 1 / 4 * 1 / 9)

p = 2 * i * i / n * (n - 1)

*/