// 1753번: 최단 경로
// 다익스트라 알고리즘 연습

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = INT32_MAX;
typedef pair<int, int> P;

// 다익스트라 알고리즘을 사용한 최단 경로 찾기
void dijkstra(int K, const vector<vector<P>> &graph, vector<int> &dist)
{
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<bool> visited(graph.size(), false);
    pq.push(P(0, K));

    while (!pq.empty())
    {
        int cur = pq.top().second; // 현재 탐색하는 정점의 번호
        visited[cur] = true;
        pq.pop();

        for (auto &p : graph[cur])
        {
            int next = p.first;
            int weight = p.second;

            if (dist[cur] + weight < dist[next])
            {
                dist[next] = dist[cur] + weight;
                if (!visited[next])
                    pq.push(P(dist[next], next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E, K; // V == 정점의 수, E == 간선의 수, K == 시작 정점의 번호
    cin >> V >> E >> K;
    vector<vector<P>> graph(V + 1); // 이어진 정점과 그 가중치
    vector<int> dist(V + 1, INF);   // 시작 정점으로부터의 거리

    for (size_t i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(P(v, w));
    }

    dist[K] = 0;
    dijkstra(K, graph, dist);
    for (size_t i = 1; i <= V; i++)
    {
        if (dist[i] != INF)
            cout << dist[i] << "\n";
        else
            cout << "INF\n";
    }
}
