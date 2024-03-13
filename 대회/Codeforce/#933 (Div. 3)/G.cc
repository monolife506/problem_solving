#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e10;

void dijkstra(int start, vector<vector<pii>> &graph, vector<ll> &dist)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[start] = 0, start});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (d > dist[cur])
            continue;

        for (auto &[nxt, w] : graph[cur])
        {
            if (dist[nxt] > dist[cur] + w)
            {
                dist[nxt] = dist[cur] + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    set<int> colors;
    map<int, int> color_num;
    vector<set<int>> node_connected_color(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        node_connected_color[u].insert(c);
        node_connected_color[v].insert(c);
        if (colors.find(c) == colors.end())
        {
            colors.insert(c);
            color_num[c] = colors.size();
        }
    }

    vector<vector<pii>> color_graph(colors.size() + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (auto c : node_connected_color[i])
        {
            color_graph[color_num[c]].push_back({colors.size() + i, 1});
            color_graph[colors.size() + i].push_back({color_num[c], 1});
        }
    }

    int b, e;
    cin >> b >> e;

    vector<ll> dist(colors.size() + n + 1, INF);
    dijkstra(colors.size() + b, color_graph, dist);
    cout << dist[colors.size() + e] / 2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}