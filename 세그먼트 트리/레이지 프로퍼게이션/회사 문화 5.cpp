#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e5;

struct SegmentTreeLazy
{
    int *tree, *lazy;

    SegmentTreeLazy(int sz)
    {
        tree = new int[sz * 4];
        lazy = new int[sz * 4];
        init(1, 1, sz);
    }

    ~SegmentTreeLazy()
    {
        delete[] tree;
        delete[] lazy;
    }

    void init(int cur, int l, int r)
    {
        lazy[cur] = -1;

        if (l == r)
        {
            tree[cur] = 1;
            return;
        }

        init(cur * 2, l, (l + r) / 2);
        init(cur * 2 + 1, (l + r) / 2 + 1, r);
        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    }

    void propagate(int cur, int l, int r)
    {
        if (lazy[cur] == -1)
            return;

        if (l != r)
        {
            lazy[cur * 2] = lazy[cur];
            lazy[cur * 2 + 1] = lazy[cur];
        }

        tree[cur] = (lazy[cur]) ? r - l + 1 : 0;
        lazy[cur] = -1;
    }

    void update(int cur, int l, int r, int L, int R, bool flag)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return;
        if (l >= L && r <= R)
        {
            lazy[cur] = flag;
            propagate(cur, l, r);
            return;
        }

        update(cur * 2, l, (l + r) / 2, L, R, flag);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, flag);
        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    }

    int get_val(int cur, int l, int r, int L, int R)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return 0;
        if (l >= L && r <= R)
            return tree[cur];

        return get_val(cur * 2, l, (l + r) / 2, L, R) +
               get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
    }
};

vector<int> tree[MAX_N + 1];
int n, m, in[MAX_N + 1], out[MAX_N + 1];

void dfs(int cur)
{
    static int nth = 0;

    in[cur] = ++nth;
    for (int nxt : tree[cur])
        dfs(nxt);

    out[cur] = nth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int parent;
        cin >> parent;
        if (parent != 0)
            tree[parent].push_back(i);
    }

    dfs(1);
    SegmentTreeLazy segtree(n);

    cin >> m;
    for (int query = 0; query < m; ++query)
    {
        int q, i;
        cin >> q >> i;

        bool init_state = segtree.get_val(1, 1, n, in[i], in[i]);
        if (q == 1)
        {
            segtree.update(1, 1, n, in[i], out[i], true);
            segtree.update(1, 1, n, in[i], in[i], init_state);
        }
        else if (q == 2)
        {
            segtree.update(1, 1, n, in[i], out[i], false);
            segtree.update(1, 1, n, in[i], in[i], init_state);
        }
        else
        {
            int val = segtree.get_val(1, 1, n, in[i], out[i]);
            cout << val - init_state << '\n';
        }
    }
}