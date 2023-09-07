#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> graph[200001];
vector<int> cycle;
map<int, int> cycle_idx;

int root[200001], depth[200001], parent[18][200001];
ll dist[18][200001];

bool find_cycle(int cur, int pre)
{
    static bool visited[200001];
    static int cycle_num = -1;

    visited[cur] = true;
    for (auto [nxt, nxt_d] : graph[cur])
    {
        if (visited[nxt])
        {
            if (nxt != pre)
            {
                cycle.push_back(cur);
                cycle_num = nxt;
                return true;
            }
        }
        else
        {
            if (find_cycle(nxt, cur))
            {
                cycle.push_back(cur);
                return cur != cycle_num;
            }
        }
    }

    return false;
}

void dfs(int cur, int p, int d, int r)
{
    parent[0][cur] = p;
    depth[cur] = d;
    root[cur] = r;

    for (auto [nxt, nxt_d] : graph[cur])
    {
        if (root[nxt] != 0 && root[cur] != root[nxt])
            continue;

        if (nxt == p)
        {
            dist[0][cur] = nxt_d;
            continue;
        }

        dfs(nxt, cur, d + 1, r);
    }
}

ll cost(int u, int v)
{
    ll ret = 0;

    if (depth[u] > depth[v])
        swap(u, v);

    for (int i = 17; i >= 0; i--)
    {
        if (depth[v] - depth[u] >= (1 << i))
        {
            ret += dist[i][v];
            v = parent[i][v];
        }
    }

    if (u != v)
    {
        for (int i = 17; i >= 0; i--)
        {
            if (parent[i][u] != -1 && parent[i][u] != parent[i][v])
            {
                ret += dist[i][u] + dist[i][v];
                u = parent[i][u];
                v = parent[i][v];
            }
        }

        ret += dist[0][u] + dist[0][v];
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    set<pii> edges;
    bool flag = false;
    for (int i = 0; i < N; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back(make_pair(v, d));
        graph[v].push_back(make_pair(u, d));

        if (u > v)
            swap(u, v);
        if (edges.find({u, v}) != edges.end())
        {
            cycle.push_back(u);
            cycle.push_back(v);
            flag = true;
        }

        edges.insert({u, v});
    }

    if (!flag)
        find_cycle(1, -1);

    for (int i = 0; i < cycle.size(); ++i)
        cycle_idx[cycle[i]] = i;

    ll cycle_sum = 0;
    vector<ll> cycle_psum(cycle.size(), 0);
    if (flag)
    {
        for (auto &[nxt, nxt_d] : graph[cycle[1]])
        {
            if (nxt == cycle[0])
            {
                if (cycle_psum[1] == 0)
                    cycle_psum[1] = nxt_d;

                cycle_sum += nxt_d;
            }
        }
    }
    else
    {
        for (int i = 1; i < cycle.size(); ++i)
        {
            for (auto &[nxt, nxt_d] : graph[cycle[i]])
            {
                if (nxt == cycle[i - 1])
                {
                    cycle_psum[i] = cycle_psum[i - 1] + nxt_d;
                    cycle_sum += nxt_d;
                    break;
                }
            }
        }

        for (auto &[nxt, nxt_d] : graph[cycle[0]])
        {
            if (nxt == cycle.back())
            {
                cycle_sum += nxt_d;
                break;
            }
        }
    }

    memset(parent, -1, sizeof(parent));
    for (int &i : cycle)
        root[i] = i;
    for (int &i : cycle)
        dfs(i, -1, 0, i);
    for (int i = 1; i <= 17; i++)
    {
        for (int j = 1; j <= 200000; j++)
        {
            if (parent[i - 1][j] != -1)
            {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
                dist[i][j] = dist[i - 1][j] + dist[i - 1][parent[i - 1][j]];
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int x, y;
        cin >> x >> y;

        if (root[x] == root[y])
        {
            cout << cost(x, y) << '\n';
        }
        else
        {
            int l_idx = cycle_idx[root[x]];
            int r_idx = cycle_idx[root[y]];
            if (l_idx > r_idx)
                swap(l_idx, r_idx);

            ll x_d = cost(root[x], x);
            ll y_d = cost(root[y], y);
            ll d = min(cycle_psum[r_idx] - cycle_psum[l_idx], cycle_sum - (cycle_psum[r_idx] - cycle_psum[l_idx]));

            cout << x_d + d + y_d << '\n';
        }
    }
}

/*

cycle and tree

*/