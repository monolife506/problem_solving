#include <iostream>
using namespace std;
typedef long long ll;

ll arr[100001];

struct SegmentTree
{
    ll *tree;

    SegmentTree(size_t n)
    {
        tree = new ll[n * 4];
        fill_n(tree, n * 4, 0);
    }

    ~SegmentTree() { delete[] tree; }

    void update(int cur, int lo, int hi, int L, int R, int k)
    {
        if (lo > R || hi < L)
            return;

        if (L <= lo && R >= hi)
        {
            tree[cur] += k;
            return;
        }
        else
        {
            int mid = (lo + hi) / 2;
            update(cur * 2, lo, mid, L, R, k);
            update(cur * 2 + 1, mid + 1, hi, L, R, k);
        }
    }

    ll getdiff(int cur, int lo, int hi, int idx)
    {
        if (lo == hi)
            return tree[cur];

        ll ret = tree[cur];
        int mid = (lo + hi) / 2;
        if (lo <= idx && idx <= mid)
            ret += getdiff(cur * 2, lo, mid, idx);
        else if (idx > mid && idx <= hi)
            ret += getdiff(cur * 2 + 1, mid + 1, hi, idx);

        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 1; i <= N; ++i)
        cin >> arr[i];

    size_t M;
    cin >> M;
    SegmentTree tree(N);
    for (size_t q = 0; q < M; ++q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            tree.update(1, 1, N, i, j, k);
        }
        else // query == 2
        {
            int x;
            cin >> x;
            cout << arr[x] + tree.getdiff(1, 1, N, x) << '\n';
        }
    }
}