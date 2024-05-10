// 9372번: 상근이의 여행
// 신장 트리 구하기

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int BFS(vector<vector<int>> &graph)
{
    int cnt = 0;
    bool visited[1001];
    memset(visited, false, sizeof(visited));

    queue<int> Q;
    Q.push(1);
    visited[1] = true;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int node : graph[cur])
        {
            if (!visited[node])
            {
                Q.push(node);
                visited[node] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        size_t N, M;
        cin >> N >> M;

        vector<vector<int>> graph(N + 1);
        for (size_t i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout << BFS(graph) << '\n';
    }
}