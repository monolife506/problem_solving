#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> get_divisors(ll num)
{
    vector<ll> ret;

    ret.push_back(1);
    for (ll i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            ret.push_back(i);
            if (num / i != i)
                ret.push_back(num / i);
        }
    }

    ret.push_back(num);

    return ret;
}

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<ll> ad = get_divisors(a);
    vector<ll> bd = get_divisors(b);
    for (int i = 0; i < ad.size(); ++i)
    {
        for (int j = 0; j < bd.size(); ++j)
        {
            ll p = ad[i] * bd[j];
            ll q = (a * b) / p;

            if (a / p != c / p && b / q != d / q)
            {
                cout << p * (a / p + 1) << " " << q * (b / q + 1) << '\n';
                return;
            }
        }
    }

    cout << -1 << " " << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}

/*

a < kp <= c
b < lq <= d

*/