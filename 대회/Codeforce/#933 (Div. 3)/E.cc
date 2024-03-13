#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e15;

struct SegmentTree
{
    vector<ll> tree;

    SegmentTree(size_t sz) { tree.resize(4 * sz, INF); }

    void update(int cur, int l, int r, int idx, ll val)
    {
        if (l > idx || r < idx)
            return;

        if (l == r)
        {
            tree[cur] = val;
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);
        tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
    }

    ll get_value(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return INF;
        if (l >= L && r <= R)
            return tree[cur];

        return min(get_value(cur * 2, l, (l + r) / 2, L, R),
                   get_value(cur * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }
};

void solve()
{
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    vector<vector<int>> depth(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> depth[i][j];
    }

    vector<ll> min_row_cost(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        SegmentTree dp(m);
        dp.update(1, 1, m, 1, 1);
        for (int j = 2; j <= m; ++j)
        {
            ll val = dp.get_value(1, 1, m, max(1, j - (d + 1)), j - 1);
            dp.update(1, 1, m, j, val + depth[i][j] + 1);
        }

        min_row_cost[i] = dp.get_value(1, 1, m, m, m);
    }

    ll total = 0;
    for (int i = 1; i <= k; ++i)
        total += min_row_cost[i];

    ll ans = total;
    for (int i = k + 1; i <= n; ++i)
    {
        total -= min_row_cost[i - k];
        total += min_row_cost[i];
        ans = min(ans, total);
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