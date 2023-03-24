#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

struct State
{
    int cur, cost;
    ll dist;
    State(int cur, int cost, ll dist) : cur(cur), cost(cost), dist(dist) {}

    bool operator<(const State &rhs) const
    {
        if (dist != rhs.dist)
            return dist > rhs.dist;
        else
            return cur > rhs.cur;
    }
};

size_t N, M;
vector<pair<int, int>> graph[2501];
int cost[2501];
ll dist[2501][2501];

ll dijkstra()
{
    priority_queue<State> pq;
    fill_n(&dist[0][0], 2501 * 2501, 1LL * 2500 * 2500 * 4000);
    pq.push({1, cost[1], dist[cost[1]][1] = 0});

    while (!pq.empty())
    {
        State top = pq.top();
        pq.pop();

        if (top.dist > dist[top.cost][top.cur])
            continue;

        for (pair<int, int> &p : graph[top.cur])
        {
            int nxt = p.first;
            int w = p.second * top.cost;
            if (dist[min(cost[nxt], top.cost)][nxt] > dist[top.cost][top.cur] + w)
            {
                dist[min(cost[nxt], top.cost)][nxt] = dist[top.cost][top.cur] + w;
                pq.push(State(nxt, min(cost[nxt], top.cost), dist[min(cost[nxt], top.cost)][nxt]));
            }
        }
    }

    ll ans = 1LL * 2500 * 2500 * 4000;
    for (size_t i = 0; i <= 2500; ++i)
        ans = min(ans, dist[i][N]);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (size_t i = 1; i <= N; ++i)
        cin >> cost[i];
    for (size_t i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout << dijkstra() << '\n';
}