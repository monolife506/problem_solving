// 11725번: 트리의 부모 찾기

#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, vector<int> &parent, vector<vector<int>> &graph)
{
    for (int &child : graph[cur])
    {
        if (parent[child] == -1)
        {
            parent[child] = cur;
            dfs(child, parent, graph);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int> parent(N + 1, -1);
    vector<vector<int>> graph(N + 1);
    parent[1] = 0;

    for (size_t i = 0; i < N - 1; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    dfs(1, parent, graph);
    for (size_t i = 2; i <= N; i++)
        cout << parent[i] << '\n';
}