#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct SegTree
{
    vector<ll> tree;

    SegTree(int n)
    {
        tree.resize(n * 4, 0);
    }

    void update(int cur, int l, int r, int idx, ll val)
    {
        if (idx < l || idx > r)
            return;

        if (l == r)
        {
            tree[cur] = val;
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);

        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    }

    ll query(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return 0;
        if (L <= l && r <= R)
            return tree[cur];

        return query(cur * 2, l, (l + r) / 2, L, R) +
               query(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    SegTree st(n);
    for (int i = 1; i <= n; ++i)
    {
        ll val;
        cin >> val;
        st.update(1, 1, n, i, val);
    }

    for (int qi = 0; qi < m + k; ++qi)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            st.update(1, 1, n, b, c);
        }
        else // a == 2
        {
            cout << st.query(1, 1, n, b, c) << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}