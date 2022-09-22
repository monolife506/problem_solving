#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

bool bfs(int start, vector<vector<pii>> &graph, vector<bool> &visited)
{
    visited.resize(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    bool flag = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (pii &p : graph[cur])
        {
            int nxt = p.first;
            int d = p.second;
            if (d < 0)
            {
                flag = false;
            }
            if (!visited[nxt])
            {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    return flag;
}

void dijkstra(int start, vector<vector<pii>> &graph, vector<ll> &dist)
{
    const ll INF = 1e18;

    dist.resize(graph.size(), INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({dist[start], start});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        ll cur_d = pq.top().first;
        pq.pop();

        if (dist[cur] < cur_d)
            continue;

        for (pii &p : graph[cur])
        {
            int nxt = p.first;
            int d = p.second;
            if (dist[nxt] > dist[cur] + d)
            {
                dist[nxt] = dist[cur] + d;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pii>> graph(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        graph[u].push_back({v, a + b});
        graph[v].push_back({u, a + b});
    }

    ll T;
    cin >> T;

    vector<int> ans;
    vector<bool> visited;
    if (bfs(1, graph, visited))
    {
        vector<ll> dist;
        dijkstra(1, graph, dist);
        for (int i = 2; i <= N; ++i)
        {
            if (dist[i] <= 2 * T)
                ans.push_back(i);
        }
    }
    else
    {
        for (int i = 2; i <= N; ++i)
        {
            if (visited[i])
                ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << " ";
    if (ans.size() != 0)
        cout << '\n';
}

/*

w[i] = a[i] + b[i]
총 거리

*/