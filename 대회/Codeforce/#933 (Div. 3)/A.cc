#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> b(n);
    for (auto &bi : b)
        cin >> bi;

    vector<int> c(m);
    for (auto &ci : c)
        cin >> ci;

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (b[i] + c[j] <= k)
                ans++;
        }
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