#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> cnt(n + m + 1, 0);
    for (int i = 1; i <= n; ++i)
        cnt[a[i]] = m + 1;

    for (int i = 0; i < m; ++i)
    {
        int p, v;
        cin >> p >> v;

        cnt[v] += m - i;
        cnt[a[p]] -= m - i;
        a[p] = v;
    }

    ll ans = 0;
    for (int i = 1; i <= n + m; ++i)
        ans += (1LL * (m + 1) * m / 2) - (1LL * (m + 1 - cnt[i]) * (m - cnt[i]) / 2);

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

cnt[1] = 3
5



*/