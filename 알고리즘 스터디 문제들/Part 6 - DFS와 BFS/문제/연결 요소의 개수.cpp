#include <iostream>
#include <array>
#include <vector>
using namespace std;

array<vector<int>, 1001> graph;
array<bool, 1001> visited = {};

void dfs(int cur)
{
    visited[cur] = true;
    for (size_t i = 0; i < graph[cur].size(); i++)
    {
        if (!visited[graph[cur][i]])
            dfs(graph[cur][i]);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    int node1, node2;
    for (size_t i = 0; i < M; i++)
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int cnt = 0;
    for (size_t i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}