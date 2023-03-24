#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, int cur_set, const vector<vector<int>> &graph, vector<char> &visited)
{
    visited[cur] = cur_set;
    for (int next : graph[cur])
        if (visited[next] == 0)
            dfs(next, -cur_set, graph, visited);
}

bool isBipartite(const vector<vector<int>> &graph)
{
    int V = graph.size() - 1;
    vector<char> visited(V + 1, 0); // 0, 1, -1

    for (size_t i = 1; i <= V; i++)
        if (visited[i] == 0)
            dfs(i, 1, graph, visited);

    for (size_t i = 1; i <= V; i++)
        for (int next : graph[i])
            if (visited[i] == visited[next])
                return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K;
    cin >> K;
    for (size_t tc = 0; tc < K; tc++)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> graph(V + 1, vector<int>());
        for (size_t i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout << (isBipartite(graph) ? "YES" : "NO") << '\n';
    }
}