#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, m;
vector<pii> tree[2][100001];
ll subtree_sz[2][100001], dist_sum[2][100001], parent_d[2][100001];

void dfs(int cur, int parent, int tree_idx)
{
    dist_sum[tree_idx][cur] = 0;
    subtree_sz[tree_idx][cur] = 1;

    for (auto [nxt, d] : tree[tree_idx][cur])
    {
        if (nxt == parent)
            continue;

        parent_d[tree_idx][nxt] = d;
        dfs(nxt, cur, tree_idx);
        dist_sum[tree_idx][cur] += dist_sum[tree_idx][nxt] + subtree_sz[tree_idx][nxt] * d;
        subtree_sz[tree_idx][cur] += subtree_sz[tree_idx][nxt];
    }
}

void dfs2(int cur, int parent, int tree_idx)
{
    if (parent != -1)
    {
        ll tree_sz = (tree_idx == 0) ? n : m;
        dist_sum[tree_idx][cur] = dist_sum[tree_idx][parent];
        dist_sum[tree_idx][cur] -= subtree_sz[tree_idx][cur] * parent_d[tree_idx][cur];
        dist_sum[tree_idx][cur] += (tree_sz - subtree_sz[tree_idx][cur]) * parent_d[tree_idx][cur];
    }

    for (auto [nxt, d] : tree[tree_idx][cur])
    {
        if (nxt == parent)
            continue;

        dfs2(nxt, cur, tree_idx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[0][a].push_back({b, c});
        tree[0][b].push_back({a, c});
    }

    dfs(1, -1, 0);
    dfs2(1, -1, 0);

    int ans_e = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (dist_sum[0][ans_e] > dist_sum[0][i])
            ans_e = i;
    }

    cin >> m;
    for (int i = 0; i < m - 1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[1][a].push_back({b, c});
        tree[1][b].push_back({a, c});
    }

    dfs(1, -1, 1);
    dfs2(1, -1, 1);

    int ans_w = 1;
    for (int i = 1; i <= m; ++i)
    {
        if (dist_sum[1][ans_w] > dist_sum[1][i])
            ans_w = i;
    }

    cout << ans_e << ' ' << ans_w << '\n';
    cout << dist_sum[0][ans_e] * m + dist_sum[1][ans_w] * n + n * m << '\n';
}

/*



*/