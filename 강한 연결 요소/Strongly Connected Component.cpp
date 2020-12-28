// 2150번: Strongly Connected Component

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs_stack(int cur, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& S)
{
    visited[cur] = true;
    for (int next : graph[cur]) {
        if (!visited[next])
            dfs_stack(next, graph, visited, S);
    }
    S.push(cur);
}

void dfs_getSCC(int cur, int idx, vector<vector<int>>& graph, vector<bool>& visited, vector<vector<int>>& SCC)
{
    visited[cur] = true;
    SCC[idx].push_back(cur);
    for (int next : graph[cur]) {
        if (!visited[next])
            dfs_getSCC(next, idx, graph, visited, SCC);
    }
}

vector<vector<int>> findSCC(vector<vector<int>>& graph)
{
    int vertexCnt = graph.size() - 1;
    vector<vector<int>> graph_reverse(vertexCnt + 1);
    vector<bool> visited(vertexCnt + 1, false);
    vector<bool> visited_reverse(vertexCnt + 1, false);

    stack<int> nodeStack;
    vector<vector<int>> SCC;

    for (size_t i = 1; i <= vertexCnt; i++) {
        for (int next : graph[i]) {
            graph_reverse[next].push_back(i);
        }
    }

    for (size_t i = 1; i <= vertexCnt; i++) {
        if (!visited[i])
            dfs_stack(i, graph, visited, nodeStack);
    }

    int idx = 0;
    while (!nodeStack.empty()) {
        int cur = nodeStack.top();
        nodeStack.pop();

        if (!visited_reverse[cur]) {
            SCC.push_back(vector<int>());
            dfs_getSCC(cur, idx++, graph_reverse, visited_reverse, SCC);
            sort(SCC[idx - 1].begin(), SCC[idx - 1].end());
        }
    }

    sort(SCC.begin(), SCC.end());
    return SCC;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V + 1);
    for (size_t i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    vector<vector<int>> SCC = findSCC(graph);

    int cnt = SCC.size();
    cout << cnt << '\n';
    for (size_t i = 0; i < SCC.size(); i++) {
        for (int num : SCC[i])
            cout << num << " ";
        cout << -1 << '\n';
    }
}