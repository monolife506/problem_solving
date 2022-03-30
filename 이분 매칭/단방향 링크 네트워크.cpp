#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int matched[1000];
bool visited[1000];

int match(int cur, vector<vector<int>> &graph)
{
    if (visited[cur])
        return false;

    visited[cur] = true;
    for (int nxt : graph[cur])
    {
        if (matched[nxt] == -1 || match(matched[nxt], graph))
        {
            matched[nxt] = cur;
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        size_t n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n);
        for (size_t i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        int match_cnt = 0;
        memset(matched, -1, sizeof(matched));
        for (size_t i = 0; i < n; ++i)
        {
            memset(visited, false, sizeof(visited));
            match_cnt += match(i, graph);
        }

        cout << match_cnt << '\n';
    }
}