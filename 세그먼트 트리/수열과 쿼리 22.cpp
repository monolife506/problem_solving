#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct SegmentTree
{
    size_t sz;
    vector<ll> tree;

    SegmentTree(size_t sz, int arr[]) : sz(sz)
    {
        tree.resize(sz * 4);
        init(1, 1, sz, arr);
    }

    void init(int cur, int l, int r, int arr[])
    {
        if (l == r)
        {
            tree[cur] = arr[l - 1];
            return;
        }

        init(cur * 2, l, (l + r) / 2, arr);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, arr);
        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    }

    void update(int cur, int l, int r, int i, int val)
    {
        if (i < l || i > r)
            return;
        if (l == r)
        {
            tree[cur] = val;
            return;
        }

        update(cur * 2, l, (l + r) / 2, i, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, i, val);
        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    }

    void update(int i, int val) { update(1, 1, sz, i, val); }

    ll query(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return 0;
        if (l >= L && r <= R)
            return tree[cur];

        return query(cur * 2, l, (l + r) / 2, L, R) +
               query(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
    }

    ll query(int L, int R) { return query(1, 1, sz, L, R); }
};

struct Query
{
    int idx, k, i, j;
    ll val;
    Query(int idx, int k, int i, int j)
        : idx(idx), k(k), i(i), j(j){};
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

    SegmentTree tree(N, A);

    size_t M;
    cin >> M;
    vector<pair<int, int>> updates;
    vector<Query> queries;
    for (size_t q = 0; q < M; ++q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int i, v;
            cin >> i >> v;
            updates.push_back({i, v});
        }
        else
        {
            int k, i, j;
            cin >> k >> i >> j;
            queries.push_back(Query(q, k, i, j));
        }
    }

    sort(queries.begin(), queries.end(),
         [](const Query &lhs, const Query &rhs) -> bool
         { return lhs.k < rhs.k; });

    int k = 0;
    for (Query &q : queries)
    {
        while (k < q.k)
        {
            tree.update(updates[k].first, updates[k].second);
            ++k;
        }

        q.val = tree.query(q.i, q.j);
    }

    sort(queries.begin(), queries.end(),
         [](const Query &lhs, const Query &rhs) -> bool
         { return lhs.idx < rhs.idx; });

    for (Query &q : queries)
        cout << q.val << '\n';
}