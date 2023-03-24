#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n;
int nxt[1000001], dfsn[1000001], scc[1000001], scc_sz[1000001], scc_cnt;
int scc_nxt[1000001], scc_indegree[1000001], cache[1000001];

int dfs_scc(int cur)
{
    static int nth = 0;
    static stack<int> s;

    int ret = dfsn[cur] = ++nth;
    s.push(cur);

    if (nxt[cur] != 0)
    {
        if (dfsn[nxt[cur]] == 0)
            ret = min(ret, dfs_scc(nxt[cur]));
        else if (scc[nxt[cur]] == 0)
            ret = min(ret, dfsn[nxt[cur]]);
    }

    if (ret == dfsn[cur])
    {
        ++scc_cnt;
        while (true)
        {
            int top = s.top();
            s.pop();

            scc[top] = scc_cnt;
            scc_sz[scc_cnt]++;
            if (top == cur)
                break;
        }
    }

    return ret;
}

void topological_sort()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        cache[i] = scc_sz[i];
        if (scc_indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (scc_nxt[cur] != 0)
        {
            cache[scc_nxt[cur]] = max(cache[scc_nxt[cur]], cache[cur] + scc_sz[scc_nxt[cur]]);
            if (--scc_indegree[scc_nxt[cur]] == 0)
                q.push(scc_nxt[cur]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        int v, w;
        cin >> v >> w;
        nxt[v + 1] = w + 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (scc[i] == 0)
            dfs_scc(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (nxt[i] != 0)
        {
            if (scc[i] != scc[nxt[i]])
            {
                scc_nxt[scc[i]] = scc[nxt[i]];
                ++scc_indegree[scc[nxt[i]]];
            }
        }
    }

    topological_sort();

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, cache[i]);

    cout << ans << '\n';
}