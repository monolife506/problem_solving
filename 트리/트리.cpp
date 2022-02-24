#include <iostream>
#include <vector>
using namespace std;

bool dfs(int cur, int pre, const vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[cur] = true;
    for (int nxt : graph[cur])
    {
        if (visited[nxt])
        {
            if (nxt == pre)
                continue;
            else
                return false;
        }

        if (!dfs(nxt, cur, graph, visited))
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m, tc = 1;
    cin >> n >> m;
    while (n != 0 || m != 0)
    {
        size_t T = 0;
        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        for (size_t i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (size_t i = 1; i <= n; ++i)
        {
            if (!visited[i] && dfs(i, -1, graph, visited))
                ++T;
        }

        cout << "Case " << tc++ << ": ";
        if (T == 0)
            cout << "No trees.\n";
        else if (T == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << T << " trees.\n";

        cin >> n >> m;
    }
}