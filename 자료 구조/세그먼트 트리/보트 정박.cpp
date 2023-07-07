#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct SegmentTree
{
    vector<ll> tree;

    SegmentTree(size_t sz)
    {
        tree.resize(4 * sz, 0);
    }

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
        tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
    }

    pair<int, ll> get_val(int cur, int l, int r, ll val)
    {
        if (l == r)
            return make_pair(l, tree[cur]);
        if (val <= tree[cur * 2])
            return get_val(cur * 2, l, (l + r) / 2, val);
        if (val <= tree[cur * 2 + 1])
            return get_val(cur * 2 + 1, (l + r) / 2 + 1, r, val);

        return make_pair(-1, 0LL);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    SegmentTree P(n);
    for (int i = 1; i <= n; ++i)
    {
        ll val;
        cin >> val;
        P.update(1, 1, n, i, val);
    }

    ll ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        ll val;
        cin >> val;

        int idx = P.get_val(1, 1, n, val).first;
        if (idx != -1)
        {
            ans += 1LL * i * idx;
            P.update(1, 1, n, idx, 0);
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