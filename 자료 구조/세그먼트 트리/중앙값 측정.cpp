#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int temp[250000];

struct SegmentTree
{
    vector<int> tree;

    SegmentTree(size_t sz) { tree.resize(65536 * 4, 0); }

    int kth(int cur, int l, int r, int k)
    {
        if (l == r)
            return l;

        if (k <= tree[cur * 2])
            return kth(cur * 2, l, (l + r) / 2, k);
        else
            return kth(cur * 2 + 1, (l + r) / 2 + 1, r, k - tree[cur * 2]);
    }

    void update(int cur, int l, int r, int idx, int val)
    {
        if (idx < l || idx > r)
            return;

        if (l == r)
        {
            tree[cur] += val;
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);
        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> temp[i];

    SegmentTree tree(N);
    for (int i = 0; i < K; ++i)
        tree.update(1, 0, 65535, temp[i], 1);

    ll ans = tree.kth(1, 0, 65535, (K + 1) / 2);
    for (int i = K; i < N; ++i)
    {
        tree.update(1, 0, 65535, temp[i - K], -1);
        tree.update(1, 0, 65535, temp[i], 1);
        ans += tree.kth(1, 0, 65535, (K + 1) / 2);
    }

    cout << ans << '\n';
}