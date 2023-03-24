#include <iostream>
using namespace std;

struct SegmentTree
{
    int *tree, *lazy;

    SegmentTree(size_t n, int arr[])
    {
        tree = new int[n * 4];
        lazy = new int[n * 4];
        init(1, 0, n - 1, arr);
    }

    ~SegmentTree()
    {
        delete[] tree;
        delete[] lazy;
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

    void update(int cur, int l, int r, int L, int R, int k)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return;
        if (l >= L && r <= R)
        {
            lazy[cur] ^= k;
            propagate(cur, l, r);
            return;
        }

        update(cur * 2, l, (l + r) / 2, L, R, k);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, k);
        tree[cur] = tree[cur * 2] ^ tree[cur * 2 + 1];
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

    void propagate(int cur, int l, int r)
    {
        if (lazy[cur] == 0)
            return;

        if (l != r)
        {
            lazy[cur * 2] ^= lazy[cur];
            lazy[cur * 2 + 1] ^= lazy[cur];
        }

        if ((r - l) % 2 == 0)
            tree[cur] ^= lazy[cur];

        lazy[cur] = 0;
    }
};

int A[500000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> A[i];

    size_t M;
    cin >> M;

    SegmentTree tree(N, A);
    for (size_t q = 0; q < M; ++q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            tree.update(1, 0, N - 1, i, j, k);
        }
        else
        {
            int i, j;
            cin >> i >> j;
            cout << tree.get_val(1, 0, N - 1, i, j) << '\n';
        }
    }
}