#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1'000'000'007;

ll fac[4'000'001];

void preprocess()
{
    fac[0] = 1;
    for (int i = 1; i <= 4'000'000; i++)
    {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
    }
}

ll fac_power(int n, int k)
{
    if (k == 1)
        return fac[n];

    ll half = fac_power(n, k / 2);
    ll ret = (half * half) % MOD;
    if (k % 2 == 1)
    {
        ret *= fac[n];
        ret %= MOD;
    }

    return ret;
}

ll bino(int n, int r)
{
    ll ret = fac[n];
    ret *= fac_power(r, MOD - 2);
    ret %= MOD;
    ret *= fac_power(n - r, MOD - 2);
    ret %= MOD;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    preprocess();

    int M;
    cin >> M;
    for (size_t tc = 0; tc < M; tc++)
    {
        int N, K;
        cin >> N >> K;
        cout << bino(N, K) << '\n';
    }
}

/*

n! / r!(n - r)!
n! * (r!(n - r)!)^(-1)
n! * (r!(n - r)!)^(MOD - 2)
n! * r!^(MOD - 2) * (n - r)!^(MOD - 2)

*/