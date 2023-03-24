#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void dfs(int cur, int parent, vector<vector<pii>> &graph, vector<bool> &visited, vector<bool> &flag)
{
    visited[cur] = true;
    for (pii p : graph[cur])
    {
        int nxt = p.first;
        int idx = p.second;
        if (nxt == parent)
            continue;

        if (!visited[nxt])
            dfs(nxt, cur, graph, visited, flag);
        else
            flag[idx] = true;
    }
}

void solve(mt19937 &gen)
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {i, u, v};
    }

    while (true)
    {
        shuffle(edges.begin(), edges.end(), gen);
        vector<vector<pii>> graph(n + 1);
        for (int i = 0; i < m; ++i)
        {
            int &idx = get<0>(edges[i]);
            int &u = get<1>(edges[i]);
            int &v = get<2>(edges[i]);

            graph[u].push_back({v, idx});
            graph[v].push_back({u, idx});
        }

        vector<bool> visited(n + 1, false), flag(m, false);
        dfs(1, -1, graph, visited, flag);

        set<int> s;
        for (int i = 0; i < m; ++i)
        {
            if (flag[get<0>(edges[i])])
            {
                s.insert(get<1>(edges[i]));
                s.insert(get<2>(edges[i]));
            }
        }

        if (m == n + 2 && s.size() == 3)
            continue;

        for (int i = 0; i < m; ++i)
            cout << flag[i];

        cout << '\n';
        break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    random_device rd;
    mt19937 gen(rd());

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve(gen);
}

/*

tree + (0 ~ 3) edges

tree -> whatever
tree + 1 ~ tree + 2 -> back || cross edge blue
tree + 3 -> !

*/