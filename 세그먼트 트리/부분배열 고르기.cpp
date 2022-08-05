#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
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

int N, A[100001];
ll psum[100001];
SegmentTree tree(400'000);

ll divide_and_conquer(int l, int r)
{
    if (l == r)
        return 1LL * A[l] * A[l];

    int mid = tree.get_val(1, 1, N, l, r).second;
    ll ret = 1LL * (psum[r] - psum[l - 1]) * A[mid];

    if (mid < r)
        ret = max(ret, divide_and_conquer(mid + 1, r));
    if (mid > l)
        ret = max(ret, divide_and_conquer(l, mid - 1));

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        psum[i] = psum[i - 1] + A[i];
        tree.update(1, 1, N, i, A[i]);
    }

    cout << divide_and_conquer(1, N) << '\n';
}