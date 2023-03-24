#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll cache[300001];

ll pow_mod(ll n, ll r)
{
    if (r == 0)
        return 1;

    ll half = pow_mod(n, r / 2);
    ll ret = (half * half) % MOD;
    return (r % 2 == 0) ? ret : (ret * (n % MOD)) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    cache[1] = m % MOD;

    ll min_a = 1;
    for (ll i = 2; i <= n; ++i)
    {
        ll divisor = gcd(min_a, i);
        if (divisor == 1)
            min_a *= (i / divisor);
        if (min_a > m)
            break;

        cache[i] = (cache[i - 1] * ((m / min_a) % MOD)) % MOD;
    }

    ll ans = 0;
    for (ll i = 1; i <= n; ++i)
    {
        ans += (pow_mod(m, i) - cache[i] + MOD) % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}

/*

m = 2

n = 1: [1], [2]
n = 2: [1, 2], [2, 2]
n = 3:
n = 4:

30 - 4 = 26

ka <= m
1 <= k <= m / a

1
2
3
2 * 2
5
2 * 3
7
2 * 2 * 2

1 2 6 6 30 210

*/