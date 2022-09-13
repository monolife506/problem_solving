#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll fac[600001];

ll pow(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll half = pow(a, b / 2);
    ll ret = (half * half) % MOD;
    return (b % 2 == 0) ? ret : (ret * (a % MOD)) % MOD;
}

ll comb(ll n, ll r)
{
    if (n < r)
        return 0;

    ll ret = fac[n];
    ret = (ret * pow(fac[r], MOD - 2)) % MOD;
    ret = (ret * pow(fac[n - r], MOD - 2)) % MOD;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i <= 600000; ++i)
        fac[i] = (fac[i - 1] * i) % MOD;

    int N;
    cin >> N;

    ll ans = 1;
    for (int i = 0; i < N; ++i)
    {
        int A, B;
        cin >> A >> B;

        ans *= (comb(A + B, A) - 1);
        ans %= MOD;
    }

    cout << ans << '\n';
}