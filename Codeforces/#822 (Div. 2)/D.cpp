#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

struct SegmentTree
{
    vector<P> tree;

    SegmentTree(size_t sz) { tree.resize(sz * 4, {0, -1}); }

    void update(int cur, int l, int r, int i, P val)
    {
        if (l > i || r < i)
            return;

        if (l == r)
        {
            tree[cur] = val;
            return;
        }

        update(cur * 2, l, (l + r) / 2, i, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, i, val);
        tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
    }

    P get_val(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return {INT64_MIN, -1};
        if (l >= L && r <= R)
            return tree[cur];

        return max(get_val(cur * 2, l, (l + r) / 2, L, R),
                   get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n + 1);
    vector<ll> psum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    int l = k, r = k;
    SegmentTree lt(n), rt(n);
    lt.update(1, 1, n, k, {a[k] + psum[k - 1], -k});
    rt.update(1, 1, n, k, {a[k] - psum[k], k});

    bool flag = false;
    while (true)
    {
        if (l == 1 || r == n)
        {
            flag = true;
            break;
        }

        P l_val = lt.get_val(1, 1, n, l, r);
        ll l_max = l_val.first - psum[l - 2];
        int l_r = -l_val.second;

        P r_val = rt.get_val(1, 1, n, l, r);
        ll r_max = r_val.first + psum[r + 1];
        int r_l = r_val.second;

        int nxt_l = l, nxt_r = r;

        if (l_max >= 0)
        {
            lt.update(1, 1, n, l - 1, {l_max + psum[l - 2], -l_r});
            rt.update(1, 1, n, l - 1, {l_max - psum[l_r], (l - 1)});
            nxt_l = l - 1;
        }
        if (r_max >= 0)
        {
            lt.update(1, 1, n, r + 1, {r_max + psum[r_l - 1], -(r + 1)});
            rt.update(1, 1, n, r + 1, {r_max - psum[r + 1], r_l});
            nxt_r = r + 1;
        }

        if (l == nxt_l && r == nxt_r)
            break;

        l = nxt_l;
        r = nxt_r;
    }

    cout << (flag ? "YES" : "NO") << '\n';
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

-1 -2 -4 6 -2 -4 -1

1
16 12
-920734269 1 -1 -1 1 -1 1 1 -1 -1 -1 3 -1 -1 -1 -1

*/