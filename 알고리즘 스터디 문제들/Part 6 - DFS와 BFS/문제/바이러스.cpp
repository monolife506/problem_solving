#include <iostream>
#include <array>
#include <vector>
using namespace std;

int cnt = 0;
array<vector<int>, 101> graph;
array<bool, 101> visited = {};

void dfs(int cur)
{
    visited[cur] = true;
    for (size_t i = 0; i < graph[cur].size(); i++)
    {
        if (!visited[graph[cur][i]])
        {
            dfs(graph[cur][i]);
            cnt++;
        }
    }
}

int main()
{
    int N, M, node1, node2;
    cin >> N >> M;

    for (size_t i = 0; i < M; i++)
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    dfs(1);
    cout << cnt;
}