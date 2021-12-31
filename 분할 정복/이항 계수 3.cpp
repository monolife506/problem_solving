#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1'000'000'007;
const int MAX_N = 4'000'000;

ll fac[MAX_N + 1];

ll pow(ll a, ll b)
{
    if (b == 1)
        return a % MOD;

    ll half = pow(a, b / 2);
    ll ret = (half * half) % MOD;
    return (b % 2 == 1) ? (ret * (a % MOD)) % MOD : ret;
}

ll combination(int n, int k)
{
    ll ret = fac[n];
    ret = (ret * (pow(fac[k], MOD - 2) % MOD)) % MOD;
    ret = (ret * (pow(fac[n - k], MOD - 2) % MOD)) % MOD;
    return ret;
}

int main()
{
    int n, k;
    cin >> n >> k;

    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * (i % MOD)) % MOD;

    cout << combination(n, k) << '\n';
}

// 페르마의 소정리를 이용한 곱셈의 역원
// a^p = a (mod p) 일 때
// a^(p - 2) = a^(-1) (mod p)
// (단, a는 정수, p는 소수)이다.

// nCk = n! * k!^(-1) * (n - k)!^(-1)
// => n! * k!^(p - 2) * (n - k)!^(p - 2)