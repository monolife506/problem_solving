#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<ll> get_divisors(ll num)
{
    vector<ll> ret = {1, num};
    for (ll i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            ret.push_back(i);
            if (num / i != i)
                ret.push_back(num / i);
        }
    }

    return ret;
}

bool is_square(ll num)
{
    ll tmp = (ll)(sqrt(num) + 0.5);
    return tmp * tmp == num;
}

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<map<ll, ll>> cache(n);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            vector<ll> divisors = get_divisors(a[i] - a[j]);
            for (ll c : divisors)
            {
                ll d = (a[i] - a[j]) / c;
                if (c >= d)
                    continue;
                if ((c + d) % 2 == 1)
                    continue;

                ll p = (c + d) / 2;
                ll x = p * p - a[i];

                if (x >= 0)
                    cache[i][x] = max(cache[i][x], cache[j][x] + 1);
            }
        }
    }

    ll ans = 1;
    for (int i = 0; i < n; ++i)
    {
        for (auto p : cache[i])
            ans = max(ans, p.second + 1);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

a[i] + x = p^2
a[j] + x = q^2
a[i] - a[j] = p^2 - q^2 = (p - q)(p + q)

p - q == d
p + q == (a[i] - a[j]) / d

2p = (a[i] - a[j]) / d + d
p = ((a[i] - a[j]) / d + d) / 2

x = p^2 - a[i]

*/