#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> graph[200001];
vector<int> cycle;
int root[200001];

bool find_cycle(int cur, int pre)
{
    static int cycle_num = -1;
    static bool visited[200001];

    visited[cur] = true;
    for (auto nxt : graph[cur])
    {
        if (visited[nxt])
        {
            if (nxt != pre)
            {
                root[cur] = cur;
                cycle.push_back(cur);
                cycle_num = nxt;
                return true;
            }
        }
        else
        {
            if (find_cycle(nxt, cur))
            {
                root[cur] = cur;
                cycle.push_back(cur);
                return cur != cycle_num;
            }
        }
    }

    return false;
}

void dfs(int cur, int parent, int r)
{
    root[cur] = r;
    for (int nxt : graph[cur])
    {
        if (root[nxt] != 0 && root[cur] != root[nxt])
            continue;
        if (nxt == parent)
            continue;

        dfs(nxt, cur, r);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    find_cycle(1, -1);
    for (int i : cycle)
        dfs(i, -1, i);

    for (int i = 0; i < Q; ++i)
    {
        int u, v;
        cin >> u >> v;
        cout << (root[u] == root[v] ? 1 : 2) << '\n';
    }
}