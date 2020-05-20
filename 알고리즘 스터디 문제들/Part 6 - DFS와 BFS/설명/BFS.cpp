#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// BFS
void bfs(size_t start, const vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<size_t> Q; // BFS 구현을 위한 큐
    Q.push(start);   // 시작점을 큐에 삽입
    visited[start] = true;
    cout << start << " ";

    while (!Q.empty())
    {
        size_t cur = Q.front();
        Q.pop();

        for (size_t i = 0; i < graph[cur].size(); i++)
        {
            if (!visited[graph[cur][i]])
            {
                Q.push(graph[cur][i]);
                visited[graph[cur][i]] = true;
                cout << graph[cur][i] << " ";
            }
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

    cout << "\nBFS의 탐색 순서\n";
    bfs(V, graph, visited);
}