// 11401번: 이항 계수 3

#define MOD_P 1'000'000'007
#include <iostream>
#include <array>
using namespace std;
typedef unsigned long long ll;

array<int, 4'000'000 + 1> fac;

ll pow_mod(ll A, ll B)
{
    if (B == 1)
        return A % MOD_P;
    ll sum = (pow_mod(A, B / 2) * pow_mod(A, B / 2)) % MOD_P;
    return (B % 2) ? ((A % MOD_P) * sum) % MOD_P : sum;
}

ll ans(ll N, ll K)
{
    ll total = (pow_mod(fac[K], MOD_P - 2) * pow_mod(fac[N - K], MOD_P - 2)) % MOD_P;
    total = (total * fac[N]) % MOD_P;
    return total;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    fac[0] = 1;
    for (size_t i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % MOD_P; // N < P
    cout << ans(N, K);
}

// 페르마의 소정리를 이용한 곱셈의 역원
// a^p = a (mod p) 일 때
// a^(p - 2) = a^(-1) (mod p)
// (단, a는 정수, p는 소수)이다.

// nCk = n! * k!^(-1) * (n - k)!^(-1)
// => n! * k!^(p - 2) * (n - k)!^(p - 2)