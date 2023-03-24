#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool visited[100000];
int scc[100000], scc_indegree[100000];

void dfs(int cur, const vector<vector<int>> &graph, stack<int> &s)
{
    visited[cur] = true;
    for (int nxt : graph[cur])
        if (!visited[nxt])
            dfs(nxt, graph, s);

    s.push(cur);
}

void dfs2(int cur, int scc_num, const vector<vector<int>> &graph)
{
    scc[cur] = scc_num;
    for (int nxt : graph[cur])
        if (scc[nxt] == -1)
            dfs2(nxt, scc_num, graph);
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
        memset(visited, false, sizeof(visited));
        memset(scc, -1, sizeof(scc));
        memset(scc_indegree, 0, sizeof(scc_indegree));

        int N, M, scc_cnt = 0, ans = -1;
        cin >> N >> M;

        vector<vector<int>> graph(N), graph_reversed(N);
        stack<int> s;

        for (size_t i = 0; i < M; i++)
        {
            int A, B;
            cin >> A >> B;
            graph[A].push_back(B);
            graph_reversed[B].push_back(A);
        }

        for (size_t i = 0; i < N; i++)
            if (!visited[i])
                dfs(i, graph, s);

        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            if (scc[top] == -1)
                dfs2(top, scc_cnt++, graph_reversed);
        }

        for (size_t i = 0; i < N; i++)
            for (int j : graph[i])
                if (scc[i] != scc[j])
                    scc_indegree[scc[j]]++;

        for (size_t i = 0; i < scc_cnt; i++)
        {
            if (scc_indegree[i] == 0)
            {
                if (ans != -1)
                {
                    ans = -1;
                    break;
                }

                ans = i;
            }
        }

        if (ans == -1)
        {
            cout << "Confused" << '\n';
        }
        else
        {
            for (size_t i = 0; i < N; i++)
                if (scc[i] == ans)
                    cout << i << '\n';
        }

        cout << '\n';
    }
}