#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998'244'353;

ll fac[4045], fac_inv[4045], cache[4045][2023];

bool is_prime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

ll pow_mod(ll n, ll k)
{
    ll ret = 1;

    n %= MOD;
    while (k > 0)
    {
        if (k % 2 == 1)
            ret = (ret * n) % MOD;
        n = (n * n) % MOD;
        k /= 2;
    }

    return ret;
}

void precompute()
{
    fac[0] = fac_inv[0] = 1;
    for (int i = 1; i <= 4044; ++i)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
        fac_inv[i] = pow_mod(fac[i], MOD - 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int n;
    cin >> n;

    map<int, int> cnt;
    for (int i = 0; i < n * 2; ++i)
    {
        int ai;
        cin >> ai;
        cnt[ai]++;
    }

    vector<pii> prime_cnt;
    for (auto p : cnt)
    {
        if (is_prime(p.first))
            prime_cnt.push_back(p);
    }

    int m = prime_cnt.size();

    if (m < n)
    {
        cout << 0 << '\n';
    }
    else
    {
        cache[0][0] = fac_inv[prime_cnt[0].second];
        cache[0][1] = fac_inv[prime_cnt[0].second - 1];
        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                cache[i][j] += (fac_inv[prime_cnt[i].second] * cache[i - 1][j]) % MOD;
                if (j != 0)
                    cache[i][j] += (fac_inv[prime_cnt[i].second - 1] * cache[i - 1][j - 1]) % MOD;
                cache[i][j] %= MOD;
            }
        }

        ll ans = (cache[m - 1][n] * fac[n]) % MOD;
        for (auto p : cnt)
        {
            if (!is_prime(p.first))
                ans = (ans * fac_inv[p.second]) % MOD;
        }

        cout << ans << '\n';
    }
}

/*

n^2
서로 다른 n개의 소수

cache[i][j]

non prime cnt: b1 b2
prime cnt: c1 c2

n! / b1! b2! ...

*/