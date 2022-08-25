#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Node
{
    int idx, x, y, z;
    Node(int idx = 0, int x = 0, int y = 0, int z = 0) : idx(idx), x(x), y(y), z(z) {}
};

Node nodes[200000];
vector<P> graph[600001];
ll dist[600001];

void dijkstra(int S = 1)
{
    fill_n(&dist[0], 600001, 1e18);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[S] = 0;
    pq.push({dist[S], S});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (d > dist[cur])
            continue;

        for (P &p : graph[cur])
        {
            int &nxt = p.first;
            int &w = p.second;
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

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        nodes[i].idx = i + 1;
        cin >> nodes[i].x >> nodes[i].y >> nodes[i].z;

        graph[nodes[i].idx].push_back({(nodes[i].z % K) + 200001, nodes[i].z});
        graph[(nodes[i].z % K) + 400001].push_back({nodes[i].idx, nodes[i].z});
    }

    graph[200001].push_back({400001, 0});
    for (int i = 1; i < K; ++i)
        graph[i + 200001].push_back({(K - i) + 400001, 0});

    sort(nodes, nodes + N, [](Node &lhs, Node &rhs) -> bool
         { return lhs.x < rhs.x; });

    for (int i = 1; i < N; ++i)
    {
        graph[nodes[i].idx].push_back({nodes[i - 1].idx, abs(nodes[i].x - nodes[i - 1].x)});
        graph[nodes[i - 1].idx].push_back({nodes[i].idx, abs(nodes[i].x - nodes[i - 1].x)});
    }

    sort(nodes, nodes + N, [](Node &lhs, Node &rhs) -> bool
         { return lhs.y < rhs.y; });

    for (int i = 1; i < N; ++i)
    {
        graph[nodes[i].idx].push_back({nodes[i - 1].idx, abs(nodes[i].y - nodes[i - 1].y)});
        graph[nodes[i - 1].idx].push_back({nodes[i].idx, abs(nodes[i].y - nodes[i - 1].y)});
    }

    dijkstra();

    for (int i = 1; i <= N; ++i)
        cout << dist[i] << '\n';
}