#include <iostream>
using namespace std;

struct SegmentTree
{
    int *tree;

    SegmentTree(int N)
    {
        tree = new int[4 * N];
        init(1, 1, N);
    }

    ~SegmentTree() { delete[] tree; }

    int init(int cur, int lo, int hi)
    {
        if (lo == hi)
            return tree[cur] = 1;

        int mid = (lo + hi) / 2;
        int L = init(cur * 2, lo, mid);
        int R = init(cur * 2 + 1, mid + 1, hi);
        return tree[cur] = L + R;
    }

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

    int N, K;
    cin >> N >> K;

    SegmentTree tree(N);
    int cur = K;

    cout << "<";
    for (int i = N; i > 0; --i)
    {
        int val = tree.kth(1, 1, N, cur);
        tree.update(1, 1, N, val, -1);

        if (i != 1)
            cur = (cur + K - 2) % (i - 1) + 1;

        cout << val;
        if (i != 1)
            cout << ", ";
    }

    cout << ">\n";
}

/*

1 2 3 4 5 6 7

*/