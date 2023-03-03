#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e16;

struct SegmentTree
{
    vector<ll> tree;
    SegmentTree(size_t sz) { tree.resize(sz * 4, INF); }

    void update(int cur, int l, int r, int i, ll val)
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
        tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
    }

    ll get_val(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return INF;
        if (L <= l && r <= R)
            return tree[cur];

        return min(get_val(cur * 2, l, (l + r) / 2, L, R),
                   get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }
};

void solve()
{
    int n, k;
    ll x;
    cin >> n >> k >> x;
    if (x < 0)
    {
        x = -x;
        k = n - k;
    }

    vector<ll> a(n + 1), psum(n + 1);
    psum[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    SegmentTree tree1(n);
    SegmentTree tree2(n);
    for (int i = 1; i <= n; ++i)
    {
        tree1.update(1, 1, n, i, psum[i - 1] + x * (i - 1));
        tree2.update(1, 1, n, i, psum[i - 1] - x * (i - 1));
    }

    ll ans = 0;
    for (int r = 1; r <= n; ++r)
    {
        ll val;
        val = tree1.get_val(1, 1, n, max(1, r - k + 1), r);
        ans = max(ans, psum[r] + x * r - val);
        if (r > k)
        {
            val = tree2.get_val(1, 1, n, 1, r - k);
            ans = max(ans, psum[r] - x * r + x * k * 2 - val);
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

/*

x > 0

r - l + 1 <= k -> l >= r - k + 1
sum + (r - l + 1)x
psum[r] - psum[l - 1] + (r - l + 1)x
(psum[r] + rx) - (psum[l - 1] + (l - 1)x)

r - l + 1 > k
sum + kx - (r - l + 1 - k)x
psum[r] - psum[l - 1] + kx - (r - l + 1 - k)x
(psum[r] - rx) - (psum[l - 1] - (l - 1)x) + 2kx

*/