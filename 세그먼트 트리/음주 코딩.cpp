#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree
{
    vector<int> tree;

    SegmentTree(size_t sz, vector<int> &v)
    {
        tree.resize(sz * 4, 0);
        for (int i = 1; i <= sz; ++i)
            update(1, 1, sz, i, v[i]);
    }

    void update(int cur, int l, int r, int idx, int val)
    {
        if (l > idx || r < idx)
            return;

        if (l == r)
        {
            tree[cur] = (val > 0) - (val < 0);
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);
        tree[cur] = tree[cur * 2] * tree[cur * 2 + 1];
    }

    int get_value(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return 1;
        if (l >= L && r <= R)
            return tree[cur];

        return get_value(cur * 2, l, (l + r) / 2, L, R) *
               get_value(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    while (cin >> N >> K)
    {
        vector<int> X(N + 1);
        for (int i = 1; i <= N; ++i)
            cin >> X[i];

        SegmentTree tree(N, X);
        for (int q = 0; q < K; ++q)
        {
            char order;
            cin >> order;
            if (order == 'C')
            {
                int i, V;
                cin >> i >> V;
                tree.update(1, 1, N, i, V);
            }
            else
            {
                int i, j;
                cin >> i >> j;

                int val = tree.get_value(1, 1, N, i, j);
                if (val > 0)
                    cout << '+';
                else if (val == 0)
                    cout << 0;
                else
                    cout << '-';
            }
        }

        cout << '\n';
    }
}