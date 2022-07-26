#include <iostream>
using namespace std;
typedef long long ll;

ll pow_mod(ll a, ll b, ll m)
{
    __int128_t ret = 1;
    __int128_t a_mod = a % m;

    while (b > 0)
    {
        if (b % 2 == 1)
            ret = (ret * a_mod) % m;
        a_mod = (a_mod * a_mod) % m;
        b /= 2;
    }

    return ret;
}

bool milller_rabin_test(ll n, ll a)
{
    ll p = n - 1;
    while (p % 2 == 0)
    {
        if (pow_mod(a, p, n) == n - 1)
            return true;
        p /= 2;
    }

    ll d = pow_mod(a, p, n);
    return d == n - 1 || d == 1;
}

bool is_prime(ll n)
{
    static const ll a[] = {2, 7, 61};

    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    if (n <= 100)
    {
        for (ll i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (!milller_rabin_test(n, a[i]))
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        ll S;
        cin >> S;
        ans += is_prime(2 * S + 1);
    }

    cout << ans << '\n';
}

/*

A = 2xy + x + y
(x + 1) * (y + 1) = xy + x + y + 1
(2x + 1) * (2y + 1) = 4xy + 2x + 2y + 1 = 2A + 1

*/