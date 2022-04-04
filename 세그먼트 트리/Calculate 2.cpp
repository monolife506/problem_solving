#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

struct SegmentTree
{
    int *tree, *lazy;

    SegmentTree(size_t n, int arr[])
    {
        tree = new int[n * 4];
        lazy = new int[n * 4];
        init(1, 1, n, arr);
    }

    void init(int cur, int l, int r, int arr[])
    {
        lazy[cur] = 0;

        if (l == r)
        {
            tree[cur] = arr[l];
            return;
        }

        init(cur * 2, l, (l + r) / 2, arr);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, arr);
        tree[cur] = tree[cur * 2] ^ tree[cur * 2 + 1];
    }

    void propagate(int cur, int l, int r)
    {
        if (lazy[cur] == 0)
            return;

        if (l != r)
        {
            lazy[cur * 2] ^= lazy[cur];
            lazy[cur * 2 + 1] ^= lazy[cur];
        }
        if ((r - l + 1) % 2 == 1)
            tree[cur] ^= lazy[cur];

        lazy[cur] = 0;
    }

    int get_val(int cur, int l, int r, int L, int R)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return 0;
        if (l >= L && r <= R)
            return tree[cur];

        return get_val(cur * 2, l, (l + r) / 2, L, R) ^
               get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
    }

    void update(int cur, int l, int r, int L, int R, int val)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return;
        if (l >= L && r <= R)
        {
            lazy[cur] ^= val;
            propagate(cur, l, r);
            return;
        }

        update(cur * 2, l, (l + r) / 2, L, R, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, val);
        tree[cur] = tree[cur * 2] ^ tree[cur * 2 + 1];
    }
};

vector<int> tree[MAX_N + 1];
int weight[MAX_N + 1], in[MAX_N + 1], out[MAX_N + 1];

void dfs(int cur, int parent)
{
    static int nth = 0;

    in[cur] = ++nth;
    for (int nxt : tree[cur])
    {
        if (nxt != parent && in[nxt] == 0)
            dfs(nxt, cur);
    }

    out[cur] = nth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N >> M;
    for (size_t i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1);
    for (size_t i = 1; i <= N; ++i)
        cin >> weight[in[i]];

    SegmentTree seg_tree(N, weight);
    for (size_t i = 0; i < M; ++i)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int x;
            cin >> x;
            cout << seg_tree.get_val(1, 1, N, in[x], out[x]) << '\n';
        }
        else
        {
            int x, y;
            cin >> x >> y;
            seg_tree.update(1, 1, N, in[x], out[x], y);
        }
    }
}