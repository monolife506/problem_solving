#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> factorization(int n)
{
    vector<pii> ret;
    if (n % 2 == 0)
    {
        int cnt = 0;
        while (n % 2 == 0)
        {
            cnt++;
            n /= 2;
        }

        ret.push_back({cnt, 2});
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i != 0)
            continue;

        int cnt = 0;
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }

        ret.push_back({cnt, i});
    }

    if (n > 2)
        ret.push_back({1, n});

    return ret;
}

void solve()
{
    int n;
    cin >> n;

    vector<pii> f = factorization(n);
    sort(f.begin(), f.end());

    vector<int> a_product(f.size());
    a_product[f.size() - 1] = f[f.size() - 1].second;
    for (int i = f.size() - 2; i >= 0; --i)
        a_product[i] = a_product[i + 1] * f[i].second;

    int ans = 0;
    for (int i = 0; i < f.size(); ++i)
    {
        if (i == 0)
            ans += a_product[i] * f[i].first;
        else
            ans += a_product[i] * (f[i].first - f[i - 1].first);
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

2^15 * 3^4 * 7^2

42^2 * 6^2 * 2^11

84 + 12 + 22 =

*/