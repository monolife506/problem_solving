#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree
{
    vector<int> tree;

    SegmentTree(int N, vector<int> &v)
    {
        tree.resize(4 * N);
        init(1, 1, N, v);
    }

    void init(int cur, int l, int r, vector<int> &v)
    {
        if (l == r)
        {
            tree[cur] = v[l];
            return;
        }

        init(cur * 2, l, (l + r) / 2, v);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, v);
        tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
    }

    int get_value(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return INT32_MAX;
        if (l >= L && r <= R)
            return tree[cur];

        return min(get_value(cur * 2, l, (l + r) / 2, L, R),
                   get_value(cur * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    SegmentTree tree(N, A);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << tree.get_value(1, 1, N, a, b) << '\n';
    }
}