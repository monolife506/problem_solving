#include <iostream>
using namespace std;

typedef unsigned long long ll;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll fac[MAX];

ll pow(ll A, ll B)
{
    if (B == 1)
        return A % MOD;

    ll half = pow(A, B / 2);
    ll sum = (half * half) % MOD;
    return (B % 2 == 0) ? (sum % MOD) : ((sum * A) % MOD);
}

ll ans(ll N, ll M)
{
    ll total = (pow(fac[M], MOD - 2) * pow(fac[N - M], MOD - 2)) % MOD;
    total = (total * fac[N]) % MOD;
    return total;
}

int main()
{
    ll N, M;
    cin >> N >> M;

    fac[0] = 1;
    for (size_t i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % MOD;

    cout << ans(N, M);
}