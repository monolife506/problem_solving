#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct MergeSortTree
{
    size_t sz;
    vector<vector<int>> tree;

    MergeSortTree(size_t n, vector<int> &arr)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;

        tree.resize(sz * 2);
        for (size_t i = sz; i < sz + n; ++i)
            tree[i].push_back(arr[i - sz]);
        for (size_t i = sz - 1; i > 0; --i)
        {
            tree[i].resize(tree[i * 2].size() + tree[i * 2 + 1].size());
            merge(tree[i * 2].begin(), tree[i * 2].end(),
                  tree[i * 2 + 1].begin(), tree[i * 2 + 1].end(),
                  tree[i].begin());
        }
    }

    int query(int L, int R, int val) // [L, R]에서 val보다 큰 값의 개수
    {
        int ret = 0;
        for (L += sz, R += sz; L < R; L /= 2, R /= 2)
        {
            if (L % 2 == 1)
            {
                ret += tree[L].end() - upper_bound(tree[L].begin(), tree[L].end(), val);
                ++L;
            }
            if (R % 2 == 0)
            {
                ret += tree[R].end() - upper_bound(tree[R].begin(), tree[R].end(), val);
                --R;
            }
        }

        if (L == R)
            ret += tree[L].end() - upper_bound(tree[L].begin(), tree[L].end(), val);

        return ret;
    }
};

int parametric_search(int L, int R, int kth, MergeSortTree &mst)
{
    int l = -1e9;
    int r = 1e9;
    int mid, ret;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mst.query(L, R, mid) <= (R - L + 1) - kth)
        {
            ret = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (size_t i = 0; i < n; ++i)
        cin >> a[i];

    MergeSortTree mst(n, a);
    for (size_t q = 0; q < m; ++q)
    {
        int i, j, k;
        cin >> i >> j >> k;
        cout << parametric_search(i - 1, j - 1, k, mst) << '\n';
    }
}