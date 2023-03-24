#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree
{
    vector<int> tree;

    SegmentTree(size_t sz, vector<int> &v)
    {
        tree.resize(sz * 4, INT32_MAX);
        for (int i = 1; i <= sz; ++i)
            update(1, 1, sz, i, v[i]);
    }

    void update(int cur, int l, int r, int i, int val)
    {
        if (i < l || i > r)
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

    int get_val(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return INT32_MAX;
        if (l >= L && r <= R)
            return tree[cur];

        return min(get_val(cur * 2, l, (l + r) / 2, L, R),
                   get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    int M;
    cin >> M;

    SegmentTree tree(N, A);
    for (int q = 0; q < M; ++q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int i, v;
            cin >> i >> v;
            tree.update(1, 1, N, i, v);
        }
        else
        {
            int i, j;
            cin >> i >> j;
            cout << tree.get_val(1, 1, N, i, j) << '\n';
        }
    }
}