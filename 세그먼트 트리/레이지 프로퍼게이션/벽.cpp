#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

struct SegmentTree
{
    const size_t n;
    vector<P> tree, lazy;

    SegmentTree(size_t n) : n(n)
    {
        tree.resize(n * 4, {0, 0});
        lazy.resize(n * 4, {0, 100'000});
    }

    void propagate(int cur, int l, int r)
    {
        if (l != r)
        {
            lazy[cur * 2].first = min(max(lazy[cur * 2].first, lazy[cur].first), lazy[cur].second);
            lazy[cur * 2].second = min(max(lazy[cur * 2].second, lazy[cur].first), lazy[cur].second);
            lazy[cur * 2 + 1].first = min(max(lazy[cur * 2 + 1].first, lazy[cur].first), lazy[cur].second);
            lazy[cur * 2 + 1].second = min(max(lazy[cur * 2 + 1].second, lazy[cur].first), lazy[cur].second);
        }

        tree[cur].first = min(max(tree[cur].first, lazy[cur].first), lazy[cur].second);
        tree[cur].second = min(max(tree[cur].second, lazy[cur].first), lazy[cur].second);
        lazy[cur].first = 0;
        lazy[cur].second = 100'000;
    }

    void update(int cur, int l, int r, int op, int L, int R, int h)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return;
        if (l >= L && r <= R)
        {
            if (op == 1)
                lazy[cur].first = h;
            else // op == 2
                lazy[cur].second = h;

            propagate(cur, l, r);
            return;
        }

        update(cur * 2, l, (l + r) / 2, op, L, R, h);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, op, L, R, h);
    }

    P get_value(int cur, int l, int r, int idx)
    {
        propagate(cur, l, r);

        if (l > idx || r < idx)
            return {0, 100'000};
        if (l == r)
            return tree[cur];

        P left = get_value(cur * 2, l, (l + r) / 2, idx);
        P right = get_value(cur * 2 + 1, (l + r) / 2 + 1, r, idx);
        return {max(left.first, right.first), min(left.second, right.second)};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    SegmentTree tree(n);
    for (int i = 0; i < k; ++i)
    {
        int op, left, right, height;
        cin >> op >> left >> right >> height;
        tree.update(1, 1, n, op, left + 1, right + 1, height);
    }
    for (int i = 1; i <= n; ++i)
    {
        P p = tree.get_value(1, 1, n, i);
        cout << p.first << '\n';
    }
}

/*

[1, 10] @ [4, 7] = [4, 7]
[1, 4] @ [7, 10] = [7, 4] -> [7, 10]
[7, 10] @ [0, 4] = [7, 4] -> [4, 4]

*/