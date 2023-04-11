#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e16;

vector<int> graph[100001];
vector<pii> graph2[200001];
int N, M, K, S, p, q;
ll cnt[100001], dist[200001];

void bfs()
{
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        if (cnt[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur])
        {
            if (cnt[nxt] > cnt[cur] + 1)
            {
                cnt[nxt] = cnt[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

void dijkstra(int S)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[S] = 0, S});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[cur])
            continue;

        for (pii p : graph2[cur])
        {
            int nxt = p.first;
            int w = p.second;
            if (dist[nxt] > dist[cur] + w)
            {
                dist[nxt] = dist[cur] + w;
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
    fill_n(&cnt[0], 100001, INF);
    fill_n(&dist[0], 200001, INF);

    cin >> N >> M >> K >> S >> p >> q;
    for (int i = 0; i < K; ++i)
    {
        int u;
        cin >> u;
        cnt[u] = 0;
    }
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if (cnt[u] != 0 && cnt[v] != 0)
        {
            graph2[u * 2].push_back({v * 2 - 1, 0});
            graph2[v * 2].push_back({u * 2 - 1, 0});
        }
    }

    bfs();

    for (int i = 1; i <= N; ++i)
        graph2[i * 2 - 1].push_back({i * 2, (cnt[i] > S) ? p : q});

    dijkstra(2);

    cout << dist[N * 2 - 1] << '\n';
}