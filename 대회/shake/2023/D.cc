#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 500000LL * 1e9;
vector<pair<int, ll>> graph[200001];
ll dist[200001];

void dijkstra(int start)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill_n(&dist[0], 200001, INF);
    pq.push({dist[start] = 0, start});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        ll cur_d = pq.top().first;
        pq.pop();

        if (cur_d > dist[cur])
            continue;

        for (auto [nxt, d] : graph[cur])
        {
            if (dist[nxt] > dist[cur] + d)
                pq.push({dist[nxt] = dist[cur] + d, nxt});
        }
    }
}

bool visited[200001];

void dfs(int cur)
{
    visited[cur] = true;
    for (auto [nxt, d] : graph[cur])
    {
        if (!visited[nxt] && dist[cur] == dist[nxt] + d)
            dfs(nxt);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, A, B;
    cin >> n >> m >> A >> B;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra(A);
    dfs(B);

    vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i])
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int num : ans)
        cout << num << ' ';

    cout << '\n';
}

/*

3 3 1 2
1 2 2
1 3 1
2 3 1

6 7 1 4
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 1 1
5 3 1

*/