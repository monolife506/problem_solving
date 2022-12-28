#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;

        if (x > y)
            swap(x, y);

        p[y] = max(p[y], x);
    }

    ll len = 1;
    ll ans = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (p[i] < i - len)
            len++;
        else
            len = i - p[i];

        ans += len;
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