#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> cnt(n / 2 + 1, 0);
    for (int i = n / 2; i > 0; --i)
    {
        cnt[i] += ((n / i) * ((n / i) - 1)) / 2;
        for (int j = i * 2; j <= n / 2; j += i)
            cnt[i] -= cnt[j];
    }

    ll ans = 0;
    for (int i = n / 2; i > 1; --i)
    {
        if (cnt[i] >= i - 1)
        {
            ll tmp = min((m / (i - 1)) * (i - 1), cnt[i] - (cnt[i] % (i - 1)));
            m -= tmp;
            ans += (tmp / (i - 1)) * i;
        }
    }

    cout << (m == 0 ? ans : -1) << '\n';
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

가능한 한 최대 k 사용하기

*/