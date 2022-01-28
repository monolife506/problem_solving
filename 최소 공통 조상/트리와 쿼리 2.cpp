#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, ll> P;

int N, M;
vector<P> tree[100001];

int depths[100001], parents[17][100001];
ll dist[17][100001];

void traverse(int cur, int parent, int depth)
{
    depths[cur] = depth;
    parents[0][cur] = parent;

    for (P &p : tree[cur])
    {
        if (p.first == parent)
        {
            dist[0][cur] = p.second;
            continue;
        }

        traverse(p.first, cur, depth + 1);
    }
}

void precompute()
{
    memset(parents, -1, sizeof(parents));
    traverse(1, -1, 0);

    for (size_t i = 1; i <= 16; i++)
    {
        for (size_t j = 1; j <= 100000; j++)
        {
            if (parents[i - 1][j] != -1)
            {
                parents[i][j] = parents[i - 1][parents[i - 1][j]];
                dist[i][j] = dist[i - 1][j] + dist[i - 1][parents[i - 1][j]];
            }
        }
    }
}

ll cost(int u, int v)
{
    ll ret = 0;

    if (depths[u] > depths[v])
        swap(u, v);

    for (int i = 16; i >= 0; i--)
    {
        if (depths[v] - depths[u] >= (1 << i))
        {
            ret += dist[i][v];
            v = parents[i][v];
        }
    }

    if (u != v)
    {
        for (int i = 16; i >= 0; i--)
        {
            if (parents[i][u] != -1 && parents[i][u] != parents[i][v])
            {
                ret += dist[i][u] + dist[i][v];
                u = parents[i][u];
                v = parents[i][v];
            }
        }

        ret += dist[0][u] + dist[0][v];
    }

    return ret;
}

int kth(int u, int v, int k)
{
    int lca = u, tmp = v;
    if (depths[lca] > depths[tmp])
        swap(lca, tmp);

    for (int i = 16; i >= 0; i--)
        if (depths[tmp] - depths[lca] >= (1 << i))
            tmp = parents[i][tmp];

    if (lca != tmp)
    {
        for (int i = 16; i >= 0; i--)
        {
            if (parents[i][lca] != -1 && parents[i][lca] != parents[i][tmp])
            {
                lca = parents[i][lca];
                tmp = parents[i][tmp];
            }
        }

        lca = parents[0][lca];
    }

    k--;
    if (depths[u] - depths[lca] >= k)
    {
        for (int i = 16; i >= 0; i--)
        {
            if (k >= (1 << i))
            {
                u = parents[i][u];
                k -= (1 << i);
            }
        }

        return u;
    }
    else
    {
        k = (depths[u] + depths[v] - 2 * depths[lca]) - k;
        for (int i = 16; i >= 0; i--)
        {
            if (k >= (1 << i))
            {
                v = parents[i][v];
                k -= (1 << i);
            }
        }

        return v;
    }

    return -1; // error
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (size_t i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    precompute();

    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        int query, u, v, k;
        cin >> query >> u >> v;

        if (query == 1)
        {
            cout << cost(u, v) << '\n';
        }
        else // query == 2
        {
            cin >> k;
            cout << kth(u, v, k) << '\n';
        }
    }
}