// 11402번: 이항 계수 4

#include <iostream>
#include <queue>
#include <array>
using namespace std;
typedef unsigned long long ll;

struct Comb
{
    ll n;
    ll k;
};

queue<Comb> Q;
array<ll, 2000 + 1> fac;
ll pow_mod(ll A, ll B, ll C)
{
    if (B == 1)
        return A % C;
    ll total = (pow_mod(A, B / 2, C) * pow_mod(A, B / 2, C)) % C;
    return (B % 2) ? (total * (A % C)) % C : total;
}

ll comb_mod(Comb C, ll P)
{
    if (C.k > C.n)
        return 0;

    ll mod = (pow_mod(fac[C.k], P - 2, P) * pow_mod(fac[C.n - C.k], P - 2, P)) % P;
    mod = (mod * fac[C.n]) % P;
    return mod;
}

int main()
{
    ll M, limit;
    Comb input;
    cin >> input.n >> input.k >> M;

    limit = input.n;
    for (ll i = 1; i <= limit; i *= M)
    {
        ll N, K;
        N = input.n % M;
        K = input.k % M;
        input.n /= M;
        input.k /= M;
        Q.push({N, K});
    }

    fac[0] = 1;
    for (size_t i = 1; i <= 2000; i++)
        fac[i] = (fac[i - 1] * (i % M)) % M;

    ll ans = 1;
    while (!Q.empty())
    {
        Comb output = Q.front();
        ans = (ans * comb_mod(output, M)) % M;
        Q.pop();
    }
    cout << ans;
}

// 뤼카의 정리 : https://en.wikipedia.org/wiki/Lucas%27s_theorem
