#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct SegmentTree
{
    vector<int> tree;

    SegmentTree(int n)
    {
        tree.resize(n * 4, 0);
    }

    void update(int cur, int l, int r, int val, int i)
    {
        if (l > i || r < i)
            return;

        if (l == r)
        {
            tree[cur] = val;
            return;
        }

        update(cur * 2, l, (l + r) / 2, val, i);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, val, i);
        tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
    }

    int get_val(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return INT32_MAX;
        if (l >= L && r <= R)
            return tree[cur];

        return min(get_val(cur * 2, l, (l + r) / 2, L, R),
                   get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<pii> m(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> m[i].first;
    for (int i = 1; i <= n; ++i)
        cin >> m[i].second;

    sort(m.begin() + 1, m.end());
    SegmentTree tree(n);
    for (int i = 1; i <= n; ++i)
        tree.update(1, 1, n, m[i].second, i);

    int cur = 1;
    int total_k = 0;
    while (k > 0 && cur <= n)
    {
        while (cur <= n && m[cur].first - total_k <= k)
            cur++;

        total_k += k;
        if (cur <= n)
            k -= tree.get_val(1, 1, n, cur, n);
    }

    cout << (cur > n ? "YES" : "NO") << '\n';
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