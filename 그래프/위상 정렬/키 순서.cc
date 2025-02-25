#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> tsort(const vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int nxt : graph[i])
            indegree[nxt]++;
    }

    queue<int> q;
    vector<bitset<500>> bset(n);
    for (int i = 0; i < n; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur])
        {
            bset[nxt] |= bset[cur];
            bset[nxt][cur] = 1;
            if (--indegree[nxt] == 0)
                q.push(nxt);
        }
    }

    vector<int> ret(n, 0);
    for (int i = 0; i < n; ++i)
        ret[i] = bset[i].count();

    return ret;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n), graph_r(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        graph[u - 1].push_back(v - 1);
        graph_r[v - 1].push_back(u - 1);
    }

    vector<int> cnt = tsort(graph);
    vector<int> cnt_r = tsort(graph_r);

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cnt[i] + cnt_r[i] == n - 1)
            ans++;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}