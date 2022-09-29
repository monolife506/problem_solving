#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, int> t;

const ll INF = 1e12;

int N, M, a[100001];
vector<pii> graph[100001];
ll dist[100001], dp[100001];

void dijkstra(int S)
{
    priority_queue<t, vector<t>, greater<t>> pq;
    fill_n(&dist[0], 100001, INF);
    pq.push({dist[S] = 0, dp[S] = a[S], S});

    while (!pq.empty())
    {
        ll cur_d = get<0>(pq.top());
        ll cur_a = get<1>(pq.top());
        int cur = get<2>(pq.top());
        pq.pop();

        if (dist[cur] < cur_d)
            continue;

        for (pii &p : graph[cur])
        {
            int nxt = p.first;
            int w = p.second;
            if (dist[nxt] > dist[cur] + w)
            {
                dist[nxt] = dist[cur] + w;
                dp[nxt] = dp[cur] + a[nxt];
                pq.push({dist[nxt], dp[nxt], nxt});
            }
            else if (dist[nxt] == dist[cur] + w && dp[nxt] < dp[cur] + a[nxt])
            {
                dp[nxt] = dp[cur] + a[nxt];
                pq.push({dist[nxt], dp[nxt], nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> a[i];

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int S, T;
    cin >> S >> T;

    dijkstra(S);

    if (dist[T] == INF)
        cout << -1 << '\n';
    else
        cout << dist[T] << " " << dp[T] << '\n';
}