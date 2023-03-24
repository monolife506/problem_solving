#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

struct MergeSortTree
{
    vector<vector<int>> tree;

    MergeSortTree(size_t sz, int arr[])
    {
        tree.resize(sz * 4);
        init(1, 1, sz, arr);
    }

    void init(int cur, int l, int r, int arr[])
    {
        if (l == r)
        {
            tree[cur].push_back(arr[l]);
            return;
        }

        init(cur * 2, l, (l + r) / 2, arr);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, arr);

        tree[cur].resize(tree[cur * 2].size() + tree[cur * 2 + 1].size());
        merge(tree[cur * 2].begin(), tree[cur * 2].end(),
              tree[cur * 2 + 1].begin(), tree[cur * 2 + 1].end(),
              tree[cur].begin());
    }

    int query(int cur, int l, int r, int L, int R, int val)
    {
        if (l > R || r < L)
            return 0;
        if (l >= L && r <= R)
            return upper_bound(tree[cur].begin(), tree[cur].end(), val) - tree[cur].begin();

        return query(cur * 2, l, (l + r) / 2, L, R, val) +
               query(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, val);
    }
};

vector<int> tree[200001];
int color[200001], color_by_dfs[200001], in[200001], out[200001];

void dfs(int cur, int parent)
{
    static int nth = 0;

    in[cur] = ++nth;
    color_by_dfs[in[cur]] = color[cur];
    for (int nxt : tree[cur])
    {
        if (nxt != parent)
            dfs(nxt, cur);
    }

    out[cur] = nth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M, C;
    cin >> N >> M >> C;
    for (size_t i = 1; i <= N; ++i)
        cin >> color[i];
    for (size_t j = 0; j < N - 1; ++j)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1);
    MergeSortTree mst(N, color_by_dfs);

    ll ans = 0;
    for (size_t query = 0; query < M; ++query)
    {
        int v, c;
        cin >> v >> c;
        ans += mst.query(1, 1, N, in[v], out[v], c);
        ans %= MOD;
    }

    cout << ans << '\n';
}