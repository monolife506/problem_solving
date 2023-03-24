#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

struct SegmentTree
{
    ll *tree, *lazy_a, *lazy_v;

    SegmentTree(size_t n, ll A[])
    {
        tree = new ll[n * 4];
        lazy_a = new ll[n * 4];
        lazy_v = new ll[n * 4];
        init(1, 1, n, A);
    }

    ~SegmentTree()
    {
        delete[] tree;
        delete[] lazy_a;
        delete[] lazy_v;
    }

    void init(int cur, int l, int r, ll A[])
    {
        lazy_a[cur] = 1;
        lazy_v[cur] = 0;

        if (l == r)
        {
            tree[cur] = A[l] % MOD;
            return;
        }

        init(cur * 2, l, (l + r) / 2, A);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, A);
        tree[cur] = (tree[cur * 2] + tree[cur * 2 + 1]) % MOD;
    }

    void propagate(int cur, int l, int r)
    {
        if (l != r)
        {
            lazy_a[cur * 2] = (lazy_a[cur] * lazy_a[cur * 2]) % MOD;
            lazy_a[cur * 2 + 1] = (lazy_a[cur] * lazy_a[cur * 2 + 1]) % MOD;
            lazy_v[cur * 2] = (lazy_v[cur] + lazy_v[cur * 2] * lazy_a[cur]) % MOD;
            lazy_v[cur * 2 + 1] = (lazy_v[cur] + lazy_v[cur * 2 + 1] * lazy_a[cur]) % MOD;
        }

        tree[cur] = (tree[cur] * lazy_a[cur] + MOD) % MOD;
        tree[cur] += (lazy_v[cur] * (r - l + 1)) % MOD;
        tree[cur] %= MOD;
        lazy_a[cur] = 1;
        lazy_v[cur] = 0;
    }

    ll get_val(int cur, int l, int r, int L, int R)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return 0;
        if (l >= L && r <= R)
            return tree[cur];

        return (get_val(cur * 2, l, (l + r) / 2, L, R) +
                get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R)) %
               MOD;
    }

    void update(int cur, int l, int r, int L, int R, ll a, ll v)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return;
        if (l >= L && r <= R)
        {
            lazy_a[cur] = (lazy_a[cur] * a) % MOD;
            lazy_v[cur] = (lazy_v[cur] + v) % MOD;
            propagate(cur, l, r);
            return;
        }

        update(cur * 2, l, (l + r) / 2, L, R, a, v);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, a, v);
        tree[cur] = (tree[cur * 2] + tree[cur * 2 + 1]) % MOD;
    }
};

ll A[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N;
    for (size_t i = 1; i <= N; ++i)
        cin >> A[i];

    SegmentTree tree(N, A);
    cin >> M;
    for (size_t i = 0; i < M; ++i)
    {
        int q, x, y, v;
        cin >> q >> x >> y;
        if (q == 1)
        {
            cin >> v;
            tree.update(1, 1, N, x, y, 1, v);
        }
        else if (q == 2)
        {
            cin >> v;
            tree.update(1, 1, N, x, y, v, 0);
        }
        else if (q == 3)
        {
            cin >> v;
            tree.update(1, 1, N, x, y, 0, v);
        }
        else
        {
            cout << tree.get_val(1, 1, N, x, y) << '\n';
        }
    }
}