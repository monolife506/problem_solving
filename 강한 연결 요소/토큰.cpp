#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> graph[200001];
int cnt[2][200001], scc_cnt, scc[200001], scc_sz[200001];

int dfs_scc(int cur)
{
    static int num, dfsn[200001];
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
        ++scc_cnt;
        while (true)
        {
            int top = scc_stack.top();
            scc_stack.pop();
            scc[top] = scc_cnt;

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

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= N; ++i)
    {
        if (scc[i] == 0)
            dfs_scc(i);
    }

    int P;
    cin >> P;
    for (int i = 0; i < P; ++i)
    {
        int a;
        cin >> a;
        ++cnt[0][scc[a]];
    }
    for (int i = 0; i < P; ++i)
    {
        int b;
        cin >> b;
        ++cnt[1][scc[b]];
    }

    bool flag = true;
    for (int i = 1; i <= scc_cnt; ++i)
    {
        if (cnt[0][i] != cnt[1][i])
        {
            flag = false;
            break;
        }
        else if (scc_sz[i] >= 2 && cnt[0][i] == scc_sz[i])
        {
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';
}