#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
ll fac[100001];

ll pow_mod(ll n, ll k)
{
    if (k == 0)
        return 1;

    ll half = pow_mod(n, k / 2);
    ll ret = (half * half) % MOD;
    return (k % 2 == 0) ? ret : (ret * n) % MOD;
}

ll c(ll n, ll r)
{
    ll ret = fac[n];
    ret *= pow_mod(fac[r], MOD - 2);
    ret %= MOD;
    ret *= pow_mod(fac[n - r], MOD - 2);
    ret %= MOD;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    fac[0] = 1;
    for (int i = 1; i <= n / 3; ++i)
        fac[i] = (fac[i - 1] * i) % MOD;

    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> w[i];

    ll ans = c(n / 3, n / 6);
    for (int i = 1; i <= n / 3; ++i)
    {
        vector<int> c(3);
        c[0] = w[i * 3 - 2];
        c[1] = w[i * 3 - 1];
        c[2] = w[i * 3];

        sort(c.begin(), c.end());
        if (c[0] == c[2])
        {
            ans *= 3;
            ans %= MOD;
        }
        else if (c[0] == c[1])
        {
            ans *= 2;
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

/*

n! / r!(n - r)!

*/