#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

size_t N, K;
vector<P> tree[100001];
int parent[18][100001], depth[100001];
ll dist[100001];

void dfs(int cur, int _parent, int _depth, ll _dist)
{
    parent[0][cur] = _parent;
    depth[cur] = _depth;
    dist[cur] = _dist;

    for (P &nxt : tree[cur])
        if (nxt.first != _parent)
            dfs(nxt.first, cur, _depth + 1, _dist + nxt.second);
}

void preprocess()
{
    memset(parent, -1, sizeof(parent));
    dfs(1, -1, 0, 0);

    for (size_t i = 1; i <= 17; ++i)
        for (size_t j = 1; j <= 100000; ++j)
            if (parent[i - 1][j] != -1)
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
}

int get_lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    for (int i = 17; i >= 0; i--)
        if (depth[u] - depth[v] >= (1 << i))
            u = parent[i][u];

    if (u == v)
        return u;

    for (int i = 17; i >= 0; i--)
    {
        if (parent[i][u] != -1 && parent[i][u] != parent[i][v])
        {
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

int query(int u, int v)
{
    int lca = get_lca(u, v);
    ll d = dist[u] + dist[v] - 2 * dist[lca];

    if (d % 2 == 1)
        return -1;
    if (dist[u] < dist[v])
        swap(u, v);

    d = d / 2;
    for (int i = 17; i >= 0; i--)
    {
        if (depth[u] - depth[lca] >= (1 << i) && dist[u] - dist[parent[i][u]] <= d)
        {
            d -= dist[u] - dist[parent[i][u]];
            u = parent[i][u];
        }
    }

    return (d == 0) ? u : -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (size_t i = 0; i < N - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    preprocess();
    for (size_t i = 0; i < K; ++i)
    {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << '\n';
    }
}