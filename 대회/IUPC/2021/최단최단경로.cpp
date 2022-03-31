#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> Edge;
typedef pair<pair<ll, int>, int> P;

const int MAX_N = 100000;
const int MOD = 1000000009;
const ll INF = 60000000001;

int N, M;
vector<Edge> graph[MAX_N + 1];

ll min_dist[MAX_N + 1];
ll dist_cnt[MAX_N + 1]; // 경로의 개수
int min_node_cnt[MAX_N + 1];

void dijkstra(int start)
{
    fill(min_dist, min_dist + (N + 1), INF);
    fill(min_node_cnt, min_node_cnt + (N + 1), MAX_N + 1);

    priority_queue<P, vector<P>, greater<P>> pq;
    min_node_cnt[start] = min_dist[start] = 0;
    dist_cnt[start] = 1;

    pq.push(P(make_pair(min_dist[start], min_node_cnt[start]), start));

    while (!pq.empty())
    {
        int cur = pq.top().second;
        ll dist = pq.top().first.first;
        int node_cnt = pq.top().first.second;
        pq.pop();

        if (dist > min_dist[cur])
            continue;

        for (Edge &e : graph[cur])
        {
            int &next = e.first;
            int &cost = e.second;

            if (min_dist[next] > dist + cost)
            {
                min_dist[next] = dist + cost;
                min_node_cnt[next] = node_cnt + 1;
                dist_cnt[next] = dist_cnt[cur] % MOD;

                pq.push(P(make_pair(min_dist[next], min_node_cnt[next]), next));
            }
            else if (min_dist[next] == dist + cost)
            {
                if (min_node_cnt[next] == node_cnt + 1)
                {
                    dist_cnt[next] += dist_cnt[cur] % MOD;
                    dist_cnt[next] %= MOD;
                }
                else if (min_node_cnt[next] > node_cnt + 1)
                {
                    dist_cnt[next] = dist_cnt[cur] % MOD;
                    min_node_cnt[next] = node_cnt + 1;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> N >> M >> x >> y;
    for (size_t i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
    }

    dijkstra(x);

    if (min_dist[y] == INF)
    {
        cout << -1 << '\n';
        return 0;
    }

    cout << min_dist[y] << '\n';
    cout << min_node_cnt[y] << '\n';
    cout << dist_cnt[y] << '\n';
}

// 최단 거리 + 최소 정점