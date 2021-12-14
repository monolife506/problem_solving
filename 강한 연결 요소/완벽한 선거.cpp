#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAX_N = 1000;

int cnt, scc_cnt;
int dfsn[MAX_N * 2 + 1];      // dfs 트리에서의 탐색 순서
bool finished[MAX_N * 2 + 1]; // SCC 추출이 완전히 종료되었는가
int scc[MAX_N * 2 + 1];

int notX(int x)
{
    return (x > MAX_N) ? x - MAX_N : x + MAX_N;
}

int dfs(int cur, const vector<vector<int>> &graph, stack<int> &scc_stack)
{
    dfsn[cur] = ++cnt;
    scc_stack.push(cur);

    int ret = dfsn[cur];
    for (int next : graph[cur])
    {
        if (dfsn[next] == 0)
            ret = min(ret, dfs(next, graph, scc_stack));
        else if (!finished[next])
            ret = min(ret, dfsn[next]);
    }

    // SCC 추출
    if (ret == dfsn[cur])
    {
        ++scc_cnt;
        while (true)
        {
            int top = scc_stack.top();
            scc_stack.pop();

            scc[top] = scc_cnt;
            finished[top] = true;
            if (top == cur)
                break;
        }
    }

    return ret;
}

bool solve2SAT(const int N, const vector<vector<int>> &graph)
{
    cnt = scc_cnt = 0;
    memset(dfsn, 0, sizeof(dfsn));
    memset(finished, false, sizeof(finished));
    memset(scc, 0, sizeof(scc));

    stack<int> scc_stack;

    for (size_t i = 1; i <= N; i++)
    {
        int not_i = notX(i);
        if (dfsn[i] == 0)
            dfs(i, graph, scc_stack);
        if (dfsn[not_i] == 0)
            dfs(not_i, graph, scc_stack);

        if (scc[i] == scc[not_i])
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    while (cin >> N)
    {
        vector<vector<int>> graph(2 * MAX_N + 1);

        cin >> M;
        for (size_t m = 0; m < M; m++)
        {
            int i, j;
            cin >> i >> j;

            i = (i > 0) ? i : notX(-i);
            j = (j > 0) ? j : notX(-j);
            graph[notX(i)].push_back(j);
            graph[notX(j)].push_back(i);
        }

        cout << solve2SAT(N, graph) << '\n';
    }
}