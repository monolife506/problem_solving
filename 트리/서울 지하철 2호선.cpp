#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> graph[3001];
vector<int> cycle;
int root[3001], dist[3001];

bool find_cycle(int cur, int pre)
{
    static int cycle_num = -1;
    static bool visited[3001];

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

void dfs(int cur, int parent, int r, int d)
{
    dist[cur] = d;
    root[cur] = r;
    for (int nxt : graph[cur])
    {
        if (root[nxt] != 0 && root[cur] != root[nxt])
            continue;
        if (nxt == parent)
            continue;

        dfs(nxt, cur, r, d + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    find_cycle(1, -1);
    for (int i : cycle)
        dfs(i, -1, i, 0);

    for (int i = 1; i <= N; ++i)
        cout << dist[i] << " ";

    cout << '\n';
}