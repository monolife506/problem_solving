#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 재귀 호출을 이용한 dfs
void dfs(size_t cur, const vector<vector<int>> &graph, vector<bool> &visited)
{
    cout << cur << " ";
    visited[cur] = true;
    for (size_t i = 0; i < graph[cur].size(); i++)
    {
        if (!visited[graph[cur][i]])
            dfs(graph[cur][i], graph, visited);
    }
}

// stl stack을 이용한 dfs
void dfs_stack(size_t V, const vector<vector<int>> &graph, vector<bool> &visited)
{
    stack<size_t> S; // 현재 dfs 상태를 나타내는 stack
    S.push(V);
    visited[V] = true;
    cout << V << " ";

    while (!S.empty())
    {
        size_t cur = S.top();
        for (size_t i = 0; i < graph[cur].size(); i++)
        {
            if (!visited[graph[cur][i]])
            {
                S.push(graph[cur][i]);
                visited[graph[cur][i]] = true;
                cout << graph[cur][i] << " ";
                break;
            }
            else if (i == graph[cur].size() - 1)
                S.pop();
        }
    }
}

int main()
{
    size_t N; // 정점의 개수 N
    size_t M; // 간선의 개수 M
    int V;    // 탐색을 시작할 정점의 번호 V
    cin >> N >> M >> V;

    int tmp1, tmp2;                     // 간선의 입력값
    vector<vector<int>> graph(N + 1);   // 무방향 그래프 - 인접 리스트 구현
    vector<bool> visited(N + 1, false); // 정점의 방문 여부를 확인하는 vector
    for (size_t i = 0; i < M; i++)      // 간선 입력
    {
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }

    // 번호 순으로 탐색해야 하는 경우 정점들의 list를 sort해준다.
    for (size_t i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    cout << "\n재귀 호출을 이용한 DFS의 탐색 순서\n";
    dfs(V, graph, visited);

    fill(visited.begin(), visited.end(), false); // visited 배열 초기화
    cout << "\n\nStack을 이용한 DFS의 탐색 순서\n";
    dfs_stack(V, graph, visited);
}
