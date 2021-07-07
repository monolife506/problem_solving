#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1'000'000'007;

ll get_gcd(ll a, ll b)
{
    ll n;
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll mul(ll n, ll k)
{
    if (k == 1)
        return n % MOD;

    ll half = mul(n, k / 2);
    ll ans = (half * half) % MOD;

    if (k % 2 == 1)
        ans = (ans * (n % MOD)) % MOD;

    return ans;
}

int main()
{
    int M;
    cin >> M;

    ll sum = 0;
    for (size_t i = 0; i < M; i++) {
        ll n, s, gcd, val;
        cin >> n >> s;

        gcd = get_gcd(n, s);
        n /= gcd;
        s /= gcd;

        val = ((s % MOD) * (mul(n, MOD - 2) % MOD)) % MOD;
        sum = ((val % MOD) + (sum % MOD)) % MOD;
    }

    cout << sum << '\n';
}

// a * b^(1,000,000,005) mod 1,000,000,007
// 이들의 gcd를 구하고 합 구하기