// 1865번: 웜홀
// 벨만-포드 알고리즘

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> P;

bool visited[501];
bool iscycle(const vector<unordered_map<int, int>> &graph, int start)
{
    int N = graph.size() - 1;
    vector<int> dist(N + 1, INF);
    dist[start] = 0;
    visited[start] = true;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            for (auto &p : graph[j])
            {
                int next = p.first;
                int w = p.second;

                if (dist[j] != INF && dist[next] > dist[j] + w)
                {
                    visited[next] = true;
                    dist[next] = dist[j] + w;
                    if (i == N - 1)
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t TC;
    cin >> TC;
    for (size_t tc = 0; tc < TC; tc++)
    {
        int N, M, W;
        cin >> N >> M >> W;
        vector<unordered_map<int, int>> graph(N + 1);

        int S, E, T;
        for (size_t i = 0; i < M; i++) // 도로들
        {
            cin >> S >> E >> T;
            if (graph[S].find(E) == graph[S].end() || graph[S][E] > T)
            {
                graph[S][E] = T;
                graph[E][S] = T;
            }
        }
        for (size_t i = 0; i < W; i++) // 웜홀들
        {
            cin >> S >> E >> T;
            if (graph[S].find(E) == graph[S].end() || graph[S][E] > -T)
                graph[S][E] = -T;
        }

        bool cycleFlag = false;
        for (size_t i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                cycleFlag = iscycle(graph, i);
                if (cycleFlag)
                    break;
            }
        }

        cout << (cycleFlag ? "YES" : "NO") << '\n';
        memset(visited, false, sizeof(visited));
    }
}