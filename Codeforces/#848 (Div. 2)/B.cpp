#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int pi;
        cin >> pi;
        pos[pi] = i;
    }

    vector<int> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];

    int ans = INT32_MAX;
    for (int i = 0; i < m - 1; ++i)
    {
        if (pos[a[i]] > pos[a[i + 1]] || pos[a[i + 1]] > pos[a[i]] + d)
        {
            cout << 0 << '\n';
            return;
        }

        ans = min(ans, pos[a[i + 1]] - pos[a[i]]);
        if (d <= n - 2)
            ans = min(ans, (d + 1) - (pos[a[i + 1]] - pos[a[i]]));
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

n = 5
d = 2
2 4

*/