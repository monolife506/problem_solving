#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e15;
ll h[200001], dist[200001];
vector<ll> graph[200001];

void dijkstra_negative_min(int start)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[start] = 0, 1});

    while (!pq.empty())
    {
        ll cur_d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur_d > dist[cur])
            continue;

        for (int nxt : graph[cur])
        {
            ll d = (h[nxt] >= h[cur]) ? (h[nxt] - h[cur]) : 0;
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
    fill_n(&dist[0], 200001, INF);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dijkstra_negative_min(1);

    ll ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (h[1] > h[i])
            ans = max(ans, (h[1] - h[i]) - dist[i]);
    }

    cout << ans << '\n';
}

/*

10 12 5

5 - 2 = 3

10 5 6 1

5 -2 5
9 - D[1]

a > b
(h[a] - h[b]) - 2D[1]



3 9 4 10

a < b
2(h[a] - h[b]) + D[2]



*/