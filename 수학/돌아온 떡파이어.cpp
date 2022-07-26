#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll pow(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;

    ll half = pow(a, b / 2, mod);
    ll ret = (half * half) % mod;
    return (b % 2 == 0) ? ret : (ret * (a % mod)) % mod;
}

ll combination(ll n, ll k, ll mod, vector<ll> &fac)
{
    if (n < k)
        return 0;

    ll ret = fac[n];
    ret = (ret * pow(fac[k], mod - 2, mod)) % mod;
    ret = (ret * pow(fac[n - k], mod - 2, mod)) % mod;
    return ret;
}

ll lucas(ll n, ll k, ll mod)
{
    vector<ll> fac(mod + 1);

    fac[0] = 1;
    for (ll i = 1; i <= mod; ++i)
        fac[i] = (fac[i - 1] * (i % mod)) % mod;

    ll ret = 1;
    while (n > 0 || k > 0)
    {
        ret = (ret * combination(n % mod, k % mod, mod, fac)) % mod;
        n /= mod;
        k /= mod;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        ll N, M;
        cin >> N >> M;

        if (N == 0 && M == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        if (N == 0 || M == 1 || N < M - 1)
        {
            cout << 0 << '\n';
            continue;
        }

        ll a = lucas(N - 1, M - 2, 97);
        ll b = lucas(N - 1, M - 2, 1031);
        ll A = 1LL * 1031 * pow(1031, 97 - 2, 97) * a;
        ll B = 1LL * 97 * pow(97, 1031 - 2, 1031) * b;

        cout << (A + B) % 100007 << '\n';
    }
}

/*

a[1] + a[2] + ... + a[N - 1] = M (a[i] > 0)

N = 3, M = 3
000 - 2C1

N = 8, M = 3
OOOOOOOO - 7C1

(N, M) -> (N - 1)C(M - 2) = k
(N - 1)C(M - 2) MOD 97 = a
(N - 1)C(M - 2) MOD 1031 = b

k % 97 = a
k % 1031 = b

k % 100007
= A + B
= 1031x + 97y

1031x % 97 = a
97y % 1031 = b

*/