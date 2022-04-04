#include <cstring>
#include <iostream>
using namespace std;

struct SegmentTree
{
    int *tree;
    bool *lazy;

    SegmentTree(size_t n)
    {
        tree = new int[n * 4];
        lazy = new bool[n * 4];
        memset(tree, 0, sizeof(int) * n * 4);
        memset(lazy, false, sizeof(bool) * n * 4);
    }

    ~SegmentTree()
    {
        delete[] tree;
        delete[] lazy;
    }

    void update(int cur, int l, int r, int L, int R)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return;
        if (l >= L && r <= R)
        {
            lazy[cur] = !lazy[cur];
            propagate(cur, l, r);
            return;
        }

        update(cur * 2, l, (l + r) / 2, L, R);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
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

    void propagate(int cur, int l, int r)
    {
        if (!lazy[cur])
            return;

        if (l != r)
        {
            lazy[cur * 2] = !lazy[cur * 2];
            lazy[cur * 2 + 1] = !lazy[cur * 2 + 1];
        }

        tree[cur] = (r - l + 1) - tree[cur];
        lazy[cur] = false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N >> M;

    SegmentTree switches(N);
    for (size_t i = 0; i < M; ++i)
    {
        int O, S, T;
        cin >> O >> S >> T;

        if (O == 0)
            switches.update(1, 1, N, S, T);
        else
            cout << switches.get_val(1, 1, N, S, T) << '\n';
    }
}
