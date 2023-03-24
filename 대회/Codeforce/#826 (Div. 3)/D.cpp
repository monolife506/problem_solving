#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct SegmentTree
{
    size_t sz;
    vector<P> tree;

    SegmentTree(size_t sz) : sz(sz) { tree.resize(sz * 4, {0, -1}); }

    void update(int cur, int l, int r, int i, int val)
    {
        if (l > i || r < i)
            return;

        if (l == r)
        {
            tree[cur] = {val, val};
            return;
        }

        update(cur * 2, l, (l + r) / 2, i, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, i, val);
        tree[cur].first = max(tree[cur * 2].first, tree[cur * 2 + 1].first);
        tree[cur].second = min(tree[cur * 2].second, tree[cur * 2 + 1].second);
    }

    P get_val(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return {INT32_MIN, INT32_MAX};
        if (l >= L && r <= R)
            return tree[cur];

        P left = get_val(cur * 2, l, (l + r) / 2, L, R);
        P right = get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);

        P ret;
        ret.first = max(left.first, right.first);
        ret.second = min(left.second, right.second);

        return ret;
    }

    P get_val(int L, int R)
    {
        return get_val(1, 1, sz, L, R);
    }
};

bool is_beautiful(int l, int r, SegmentTree &tree, int &cnt)
{
    if (l == r)
        return true;

    if (!is_beautiful(l, (l + r) / 2, tree, cnt) || !is_beautiful((l + r) / 2 + 1, r, tree, cnt))
        return false;

    if (tree.get_val(l, (l + r) / 2).second - tree.get_val((l + r) / 2 + 1, r).first == 1)
    {
        ++cnt;
        return true;
    }
    else if (tree.get_val((l + r) / 2 + 1, r).second - tree.get_val(l, (l + r) / 2).first == 1)
    {
        return true;
    }

    return false;
}

void solve()
{
    int m;
    cin >> m;

    SegmentTree tree(m);
    for (int i = 1; i <= m; ++i)
    {
        int num;
        cin >> num;
        tree.update(1, 1, m, i, num);
    }

    int ans = 0;
    if (is_beautiful(1, m, tree, ans))
    {
        cout << ans << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
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

1
1

3 4 5 6

*/