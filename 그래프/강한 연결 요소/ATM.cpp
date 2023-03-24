#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int scc_num, scc[500001], scc_indegree[500001], money[500001], scc_money[500001], cache[500001];
vector<int> graph[500001], scc_graph[500001];

int dfs_scc(int cur)
{
    static int num, dfsn[500001];
    static stack<int> scc_stack;

    dfsn[cur] = ++num;
    scc_stack.push(cur);

    int ret = dfsn[cur];
    for (int nxt : graph[cur])
    {
        if (dfsn[nxt] == 0)
            ret = min(ret, dfs_scc(nxt));
        else if (scc[nxt] == 0)
            ret = min(ret, dfsn[nxt]);
    }

    if (ret == dfsn[cur])
    {
        scc_num++;
        while (true)
        {
            int top = scc_stack.top();
            scc_stack.pop();

            scc[top] = scc_num;
            scc_money[scc_num] += money[top];
            if (top == cur)
                break;
        }
    }

    return ret;
}

void make_scc_graph(int N)
{
    for (int cur = 1; cur <= N; cur++)
    {
        for (int nxt : graph[cur])
        {
            if (scc[cur] != scc[nxt])
            {
                scc_graph[scc[cur]].push_back(scc[nxt]);
                scc_indegree[scc[nxt]]++;
            }
        }
    }
}

void topological_sort(int S)
{
    queue<int> q;
    for (size_t i = 1; i <= scc_num; i++)
    {
        cache[i] = INT32_MIN;
        if (scc_indegree[i] == 0)
            q.push(i);
    }

    cache[scc[S]] = scc_money[scc[S]];

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : scc_graph[cur])
        {
            cache[nxt] = max(cache[nxt], cache[cur] + scc_money[nxt]);
            if (--scc_indegree[nxt] == 0)
                q.push(nxt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, S, P, ans = 0;
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (size_t i = 1; i <= N; i++)
        cin >> money[i];

    cin >> S >> P;

    for (size_t i = 1; i <= N; i++)
        if (scc[i] == 0)
            dfs_scc(i);

    make_scc_graph(N);
    topological_sort(S);

    for (size_t i = 0; i < P; i++)
    {
        int p;
        cin >> p;
        ans = max(ans, cache[scc[p]]);
    }

    cout << ans << '\n';
}