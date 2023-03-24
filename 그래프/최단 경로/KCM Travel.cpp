// 10217번: KCM Travel

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int INF = 1000000000;

struct Edge
{
    int v; // 도착점
    int c; // 소모 비용
    int d; // 거리 (시간)

    Edge(int end, int cost, int dist) : v(end), c(cost), d(dist) {}
};
struct Node
{
    int u; // 현재 위치
    int c; // 남은 비용
    int d; // 이동한 거리 (시간)

    Node(int cur, int cost, int dist) : u(cur), c(cost), d(dist) {}
    Node(){};
};
struct cmp
{
    bool operator()(Node &A, Node &B)
    {
        return A.d > B.d;
    }
};

int N, M, K;
int dijkstra(vector<vector<Edge>> &graph)
{
    vector<vector<int>> dist(M + 1, vector<int>(N + 1, INF));
    vector<vector<bool>> visited(M + 1, vector<bool>(N + 1, false));
    priority_queue<Node, vector<Node>, cmp> pq;

    int min_dist = INF;
    pq.push(Node(1, M, 0));
    dist[M][1] = 0;

    while (!pq.empty())
    {
        Node cur;
        do
        {
            cur = pq.top();
            pq.pop();
        } while (!pq.empty() && visited[cur.c][cur.u]);

        if (visited[cur.c][cur.u])
            break;

        visited[cur.c][cur.u] = true;
        for (auto &edge : graph[cur.u])
        {
            int C = cur.c - edge.c;
            if (C >= 0 && dist[C][edge.v] > dist[cur.c][cur.u] + edge.d)
            {
                dist[C][edge.v] = dist[cur.c][cur.u] + edge.d;

                if (edge.v == N)
                    min_dist = min(min_dist, dist[C][edge.v]);

                if (!visited[C][edge.v])
                    pq.push(Node(edge.v, C, dist[C][edge.v]));
            }
        }
    }

    return min_dist;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    size_t T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> N >> M >> K;

        vector<vector<Edge>> graph(N + 1);
        for (size_t j = 0; j < K; j++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            graph[u].push_back(Edge(v, c, d));
        }

        int ans = dijkstra(graph);
        if (ans != INF)
            cout << ans << '\n';
        else
            cout << "Poor KCM" << '\n';
    }
}