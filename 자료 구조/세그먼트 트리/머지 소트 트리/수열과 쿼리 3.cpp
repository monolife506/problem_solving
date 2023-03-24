#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct MergeSortTree
{
    int sz;
    vector<vector<int>> tree;

    MergeSortTree(int n, vector<int> &arr)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;

        tree.resize(sz * 2);
        for (int i = sz + 1; i <= sz + n; ++i)
            tree[i].push_back(arr[i - (sz + 1)]);
        for (int i = sz - 1; i > 0; --i)
        {
            tree[i].resize(tree[i * 2].size() + tree[i * 2 + 1].size());
            merge(tree[i * 2].begin(), tree[i * 2].end(),
                  tree[i * 2 + 1].begin(), tree[i * 2 + 1].end(),
                  tree[i].begin());
        }
    }

    int query(int L, int R, int val)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, last_ans = 0;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    MergeSortTree tree(N, A);
    cin >> M;
    for (int q = 0; q < M; ++q)
    {
        int a, b, c;
        cin >> a >> b >> c;
        last_ans = tree.query((a ^ last_ans), (b ^ last_ans), c ^ last_ans);
        cout << last_ans << '\n';
    }
}