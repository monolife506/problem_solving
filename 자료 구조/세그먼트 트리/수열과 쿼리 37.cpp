#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree
{
    vector<int> tree[2];

    SegmentTree(size_t sz)
    {
        tree[0].resize(sz * 4, 0);
        tree[1].resize(sz * 4, 0);
    }

    void update(int cur, int l, int r, int idx, int val)
    {
        if (idx < l || idx > r)
            return;

        if (l == r)
        {
            tree[0][cur] = (val % 2 == 0);
            tree[1][cur] = (val % 2 == 1);
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);
        tree[0][cur] = tree[0][cur * 2] + tree[0][cur * 2 + 1];
        tree[1][cur] = tree[1][cur * 2] + tree[1][cur * 2 + 1];
    }

    int get_value(int cur, int l, int r, int m, int L, int R)
    {
        if (l > R || r < L)
            return 0;
        if (l >= L && r <= R)
            return tree[m][cur];

        return get_value(cur * 2, l, (l + r) / 2, m, L, R) +
               get_value(cur * 2 + 1, (l + r) / 2 + 1, r, m, L, R);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    SegmentTree tree(N);
    for (int i = 1; i <= N; ++i)
    {
        int Ai;
        cin >> Ai;
        tree.update(1, 1, N, i, Ai);
    }

    int M;
    cin >> M;
    for (int q = 0; q < M; ++q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int i, x;
            cin >> i >> x;
            tree.update(1, 1, N, i, x);
        }
        else if (query == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << tree.get_value(1, 1, N, 0, l, r) << '\n';
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << tree.get_value(1, 1, N, 1, l, r) << '\n';
        }
    }
}