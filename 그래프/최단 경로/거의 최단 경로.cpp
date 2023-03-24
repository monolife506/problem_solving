#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int MAX_N = 500;
const int INF = 987654321;

int N;
int graph[MAX_N][MAX_N];
vector<int> prev_node[MAX_N]; // 최단 경로가 될 수 있는 이전 점들의 후보

int dijkstra(int start, int dest, bool trace)
{
    vector<int> dist(N, INF);

    priority_queue<P, vector<P>, greater<P>> pq;
    dist[start] = 0;
    pq.push(P(dist[start], start));

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
            continue;

        for (size_t next = 0; next < N; next++)
        {
            if (graph[cur][next] == -1)
                continue;

            int next_cost = cost + graph[cur][next];
            if (trace && dist[next] == next_cost)
            {
                prev_node[next].push_back(cur);
                continue;
            }

            if (dist[next] > next_cost)
            {
                dist[next] = next_cost;
                pq.push(P(dist[next], next));

                if (trace)
                {
                    prev_node[next].clear();
                    prev_node[next].push_back(cur);
                }
            }
        }
    }

    return (dist[dest] == INF) ? -1 : dist[dest];
}

// 최단 경로들을 이루는 간선들 지우기
void deletePath(int cur)
{
    for (int pre : prev_node[cur])
    {
        if (graph[pre][cur] != -1)
        {
            graph[pre][cur] = -1;
            deletePath(pre);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        int M, S, D;
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        memset(graph, -1, sizeof(graph));
        fill(prev_node, prev_node + N, vector<int>(0));

        cin >> S >> D;
        for (size_t i = 0; i < M; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            graph[u][v] = p;
        }

        dijkstra(S, D, true);
        deletePath(D);
        cout << dijkstra(S, D, false) << '\n';
    }
}

/*
V = 500
E = 10000
O(V + E)

한번의 다익스트라로 모든 최단 경로 찾기
그 최단 경로들을 지우고 다시 그래프에 대해 다익스트라 실행
*/