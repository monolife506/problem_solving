#include <iostream>
#include <array>
#include <vector>
#include <queue>
using namespace std;

array<vector<int>, 101> graph;
array<int, 101> visited;

void bfs(int start, int target)
{
    queue<int> Q;

    Q.push(start);
    visited[start] = 0;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (size_t i = 0; i < graph[cur].size(); i++)
        {
            if (visited[graph[cur][i]] == -1)
            {
                Q.push(graph[cur][i]);
                visited[graph[cur][i]] = visited[cur] + 1;
                if (graph[cur][i] == target)
                    return;
            }
        }
    }
}

int main()
{
    visited.fill(-1);

    int N, start, target;
    cin >> N >> start >> target;

    size_t M;
    cin >> M;
    int node1, node2;
    for (size_t i = 0; i < M; i++)
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    bfs(start, target);
    cout << visited[target];
}