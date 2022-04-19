#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct MergeSortTree
{
    size_t sz;
    vector<vector<int>> tree;

    MergeSortTree(size_t sz, vector<int> &arr) : sz(sz)
    {
        tree.resize(sz * 4);
        init(1, 1, sz, arr);
    }

    void init(int cur, int l, int r, vector<int> &arr)
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

    void get_candidate(int cur, int l, int r, int L, int R, vector<int> &v)
    {
        if (l > R || r < L)
            return;
        if (l >= L && r <= R)
        {
            v.push_back(tree[cur][tree[cur].size() / 2]);
            return;
        }

        get_candidate(cur * 2, l, (l + r) / 2, L, R, v);
        get_candidate(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, v);
    }

    void get_candidate(int L, int R, vector<int> &v)
    {
        get_candidate(1, 1, sz, L, R, v);
    }

    int get_cnt(int cur, int l, int r, int L, int R, int c)
    {
        if (l > R || r < L)
            return 0;
        if (l >= L && r <= R)
            return upper_bound(tree[cur].begin(), tree[cur].end(), c) -
                   lower_bound(tree[cur].begin(), tree[cur].end(), c);

        return get_cnt(cur * 2, l, (l + r) / 2, L, R, c) +
               get_cnt(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, c);
    }

    int get_cnt(int L, int R, int c)
    {
        return get_cnt(1, 1, sz, L, R, c);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M, C;
    cin >> N >> C;

    vector<int> arr(N);
    for (size_t i = 0; i < N; ++i)
        cin >> arr[i];

    MergeSortTree tree(N, arr);
    cin >> M;
    for (size_t i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;

        vector<int> candidate;
        tree.get_candidate(A, B, candidate);
        for (size_t j = 0; j < candidate.size(); ++j)
        {
            int &num = candidate[j];
            if (tree.get_cnt(A, B, num) > (B - A + 1) / 2)
            {
                cout << "yes " << num << '\n';
                break;
            }
            else if (j == candidate.size() - 1)
            {
                cout << "no" << '\n';
            }
        }
    }
}