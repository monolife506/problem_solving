#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<ll> factorization(ll n)
{
    vector<ll> ret;
    if (n % 2 == 0)
    {
        ll cnt = 0;
        while (n % 2 == 0)
        {
            n /= 2;
            cnt++;
        }

        ret.push_back(cnt);
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i != 0)
            continue;

        ll cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }

        ret.push_back(cnt);
    }

    if (n > 2)
        ret.push_back(1);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N;
    cin >> N;

    vector<ll> v = factorization(N);

    ll ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        ll cnt = 0;
        while ((cnt + 1) * (cnt + 2) / 2 <= v[i])
            cnt++;

        ans += cnt;
    }

    cout << ans << '\n';
}