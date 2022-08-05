#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll INF = 50000000001;

int N, M, K;
vector<P> graph[10001];
ll dist[21][10001];

void dijkstra()
{
    priority_queue<pair<ll, P>, vector<pair<ll, P>>, greater<pair<ll, P>>> pq;
    dist[0][1] = 0;
    pq.push({dist[0][1], {0, 1}});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int k = pq.top().second.first;
        int cur = pq.top().second.second;
        pq.pop();

        if (d > dist[k][cur])
            continue;

        for (P &p : graph[cur])
        {
            int nxt = p.first;
            int w = p.second;

            if (dist[k][nxt] > dist[k][cur] + w)
            {
                dist[k][nxt] = dist[k][cur] + w;
                pq.push({dist[k][nxt], {k, nxt}});
            }
            if (k < K && dist[k + 1][nxt] > dist[k][cur])
            {
                dist[k + 1][nxt] = dist[k][cur];
                pq.push({dist[k + 1][nxt], {k + 1, nxt}});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&dist[0][0], 21 * 10001, INF);

    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra();

    ll ans = INF;
    for (int k = 0; k <= K; ++k)
        ans = min(ans, dist[k][N]);

    cout << ans << '\n';
}