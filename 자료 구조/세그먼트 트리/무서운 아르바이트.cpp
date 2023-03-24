#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct SegmentTree
{
    vector<P> tree;

    SegmentTree(size_t sz) { tree.resize(sz * 4, {INT32_MAX, -1}); }

    void update(int cur, int l, int r, int idx, int val)
    {
        if (idx < l || idx > r)
            return;

        if (l == r)
        {
            tree[cur].first = val;
            tree[cur].second = l;
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);
        tree[cur] = (tree[cur * 2].first <= tree[cur * 2 + 1].first) ? tree[cur * 2] : tree[cur * 2 + 1];
    }

    P get_val(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return {INT32_MAX, -1};
        if (l >= L && r <= R)
            return tree[cur];

        P left = get_val(cur * 2, l, (l + r) / 2, L, R);
        P right = get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
        return (left.first <= right.first) ? left : right;
    }
};

int n, T[100001];

ll divide_and_conquer(int l, int r, SegmentTree &tree)
{
    if (l > r)
        return -1;

    int mid = tree.get_val(1, 1, n, l, r).second;

    ll ret = 1LL * T[mid] * (r - l + 1);
    ret = max(ret, divide_and_conquer(l, mid - 1, tree));
    ret = max(ret, divide_and_conquer(mid + 1, r, tree));

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> T[i];

    SegmentTree tree(n);
    for (int i = 1; i <= n; ++i)
        tree.update(1, 1, n, i, T[i]);

    cout << divide_and_conquer(1, n, tree) << '\n';
}
