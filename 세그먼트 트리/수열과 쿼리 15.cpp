#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

struct SegmentTree
{
    vector<P> tree;

    SegmentTree(size_t sz)
    {
        tree.resize(sz * 4, {INT32_MAX, -1});
    }

    void update(int cur, int l, int r, int i, int val)
    {
        if (i < l || i > r)
            return;
        if (l == r)
        {
            tree[cur] = {val, l};
            return;
        }

        update(cur * 2, l, (l + r) / 2, i, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, i, val);

        if (tree[cur * 2].first <= tree[cur * 2 + 1].first)
            tree[cur] = tree[cur * 2];
        else
            tree[cur] = tree[cur * 2 + 1];
    }

    P get_val(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return {INT32_MAX, -1};
        if (l >= L && r <= R)
            return tree[cur];

        P left = get_val(cur * 2, l, (l + r) / 2, L, R);
        P right = get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);

        if (left.first <= right.first)
            return left;
        else
            return right;
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
        int num;
        cin >> num;
        tree.update(1, 1, N, i, num);
    }

    int M;
    cin >> M;
    for (int query = 0; query < M; ++query)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int i, v;
            cin >> i >> v;
            tree.update(1, 1, N, i, v);
        }
        else
        {
            cout << tree.get_val(1, 1, N, 1, N).second << '\n';
        }
    }
}