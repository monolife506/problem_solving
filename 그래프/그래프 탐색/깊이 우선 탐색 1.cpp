#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, const vector<vector<int>> &graph, vector<int> &in)
{
    static int nth = 0;

    in[cur] = ++nth;
    for (int nxt : graph[cur])
    {
        if (in[nxt] == 0)
            dfs(nxt, graph, in);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> graph(N + 1);
    vector<int> in(N + 1, 0);
    for (size_t i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (size_t i = 1; i <= N; ++i)
        sort(graph[i].begin(), graph[i].end());

    dfs(R, graph, in);
    for (size_t i = 1; i <= N; ++i)
        cout << in[i] << '\n';
}