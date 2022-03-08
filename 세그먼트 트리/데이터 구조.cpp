#include <iostream>
using namespace std;

struct SegmentTree
{
    int *tree;

    SegmentTree()
    {
        tree = new int[4 * 2'000'001];
        fill_n(tree, 4 * 2'000'001, 0);
    }

    ~SegmentTree() { delete[] tree; }

    void update(int cur, int lo, int hi, int idx, int val)
    {
        if (idx < lo || idx > hi)
            return;

        tree[cur] += val;
        if (lo != hi)
        {
            int mid = (lo + hi) / 2;
            update(cur * 2, lo, mid, idx, val);
            update(cur * 2 + 1, mid + 1, hi, idx, val);
        }
    }

    int kth(int cur, int lo, int hi, int k)
    {
        if (lo == hi)
            return lo;

        int mid = (lo + hi) / 2;
        if (k <= tree[cur * 2])
            return kth(cur * 2, lo, mid, k);
        else
            return kth(cur * 2 + 1, mid + 1, hi, k - tree[cur * 2]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;

    SegmentTree tree;
    for (size_t i = 0; i < N; ++i)
    {
        int T, X;
        cin >> T >> X;
        if (T == 1)
        {
            tree.update(1, 1, 2'000'000, X, 1);
        }
        else // T == 2
        {
            int val = tree.kth(1, 1, 2'000'000, X);
            cout << val << '\n';
            tree.update(1, 1, 2'000'000, val, -1);
        }
    }
}