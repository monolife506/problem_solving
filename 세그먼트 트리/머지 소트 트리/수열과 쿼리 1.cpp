#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct MergeSortTree
{
    size_t sz;
    vector<vector<int>> tree;

    MergeSortTree(size_t sz, int arr[]) : sz(sz)
    {
        tree.resize(sz * 4);
        init(1, 1, sz, arr);
    }

    void init(int cur, int l, int r, int arr[])
    {
        if (l == r)
        {
            tree[cur].push_back(arr[l - 1]);
            return;
        }

        init(cur * 2, l, (l + r) / 2, arr);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, arr);

        tree[cur].resize(tree[cur * 2].size() + tree[cur * 2 + 1].size());
        merge(tree[cur * 2].begin(), tree[cur * 2].end(),
              tree[cur * 2 + 1].begin(), tree[cur * 2 + 1].end(),
              tree[cur].begin());
    }

    int query(int cur, int l, int r, int L, int R, int k)
    {
        if (l > R || r < L)
            return 0;
        if (l >= L && r <= R)
            return tree[cur].end() - upper_bound(tree[cur].begin(), tree[cur].end(), k);

        return query(cur * 2, l, (l + r) / 2, L, R, k) +
               query(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, k);
    }

    int query(int L, int R, int k) { return query(1, 1, sz, L, R, k); }
};

int A[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> A[i];

    MergeSortTree tree(N, A);

    size_t M;
    cin >> M;
    for (size_t q_cnt = 0; q_cnt < M; ++q_cnt)
    {
        int i, j, k;
        cin >> i >> j >> k;
        cout << tree.query(i, j, k) << '\n';
    }
}