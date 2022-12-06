#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fac[5001], c[5001][5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, p;
    cin >> n >> p;

    fac[0] = 1;
    for (ll i = 1; i <= n; ++i)
        fac[i] = (fac[i - 1] * i) % p;

    c[0][0] = 1;
    for (ll i = 1; i <= n; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for (ll j = 1; j < i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
    }

    if (n % 2 == 0)
    {
        ll ans = (fac[n - 2] * n) % p;
        for (ll i = 2; i <= n / 2; ++i)
        {
            for (ll j = 0; j <= i - 2; ++j)
            {
                ll tmp = (((i * c[i - 2][j]) % p) * fac[n - (3 + j)]) % p;
                ans += (tmp * n) % p;
                ans %= p;
            }
        }

        cout << ans << '\n';
    }
    else
    {
        ll ans = 0;
        for (ll i = 2; i <= n / 2 + 1; ++i)
        {
            for (ll j = 0; j <= i - 2; ++j)
            {
                ll tmp = ((((i - 1) * c[i - 2][j]) % p) * fac[n - (3 + j)]) % p;
                ans += (tmp * n) % p;
                ans %= p;
            }
        }

        cout << ans << '\n';
    }
}