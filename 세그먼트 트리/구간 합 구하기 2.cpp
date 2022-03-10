#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct LazySegmentTree
{
    ll *tree, *lazy;

    LazySegmentTree(size_t n, const vector<int> &v)
    {
        tree = new ll[n * 4];
        lazy = new ll[n * 4];
        init(1, 1, n, v);
    }

    ~LazySegmentTree()
    {
        delete[] tree;
        delete[] lazy;
    }

    void init(int cur, int l, int r, const vector<int> &v)
    {
        if (l == r)
        {
            tree[cur] = v[l];
            return;
        }

        init(cur * 2, l, (l + r) / 2, v);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, v);
        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    }

    void propagate(int cur, int l, int r)
    {
        if (lazy[cur] == 0)
            return;

        if (l != r)
        {
            lazy[cur * 2] += lazy[cur];
            lazy[cur * 2 + 1] += lazy[cur];
        }

        tree[cur] += (r - l + 1) * lazy[cur];
        lazy[cur] = 0;
    }

    void update(int cur, int l, int r, int L, int R, int val)
    {
        propagate(cur, l, r);

        if (r < L || l > R)
            return;
        if (l >= L && r <= R)
        {
            lazy[cur] += val;
            propagate(cur, l, r);
            return;
        }

        update(cur * 2, l, (l + r) / 2, L, R, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, val);
        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    }

    ll get_val(int cur, int l, int r, int L, int R)
    {
        propagate(cur, l, r);

        if (r < L || l > R)
            return 0;
        if (l >= L && r <= R)
            return tree[cur];

        return get_val(cur * 2, l, (l + r) / 2, L, R) +
               get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M, K;
    cin >> N >> M >> K;

    vector<int> v(N + 1);
    for (size_t i = 1; i <= N; ++i)
        cin >> v[i];

    LazySegmentTree tree(N, v);
    for (size_t q = 0; q < M + K; ++q)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            ll b, c, d;
            cin >> b >> c >> d;
            tree.update(1, 1, N, b, c, d);
        }
        else // a == 2
        {
            ll b, c;
            cin >> b >> c;
            cout << tree.get_val(1, 1, N, b, c) << '\n';
        }
    }
}