#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int node_num, scc_num, dfsn[100001], scc[100001], scc_indegree[100001];
stack<int> s;

int dfs_scc(int cur, const vector<vector<int>> &graph)
{
    dfsn[cur] = ++node_num;
    s.push(cur);

    int ret = dfsn[cur];
    for (int nxt : graph[cur])
    {
        if (dfsn[nxt] == 0)
            ret = min(ret, dfs_scc(nxt, graph));
        else if (scc[nxt] == 0)
            ret = min(ret, dfsn[nxt]);
    }

    if (ret == dfsn[cur])
    {
        ++scc_num;
        while (true)
        {
            int top = s.top();
            s.pop();

            scc[top] = scc_num;
            if (top == cur)
                break;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;

    for (size_t tc = 0; tc < T; tc++)
    {
        node_num = scc_num = 0;
        memset(dfsn, 0, sizeof(dfsn));
        memset(scc, 0, sizeof(scc));
        memset(scc_indegree, 0, sizeof(scc_indegree));
        while (!s.empty())
            s.pop();

        int N, M, ans = 0;
        cin >> N >> M;

        vector<vector<int>> graph(N + 1);
        for (size_t i = 0; i < M; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }

        for (size_t i = 1; i <= N; i++)
            if (dfsn[i] == 0)
                dfs_scc(i, graph);

        for (size_t i = 1; i <= N; i++)
            for (int j : graph[i])
                if (scc[i] != scc[j])
                    scc_indegree[scc[j]]++;

        for (size_t i = 1; i <= scc_num; i++)
            if (scc_indegree[i] == 0)
                ans++;

        cout << ans << '\n';
    }
}