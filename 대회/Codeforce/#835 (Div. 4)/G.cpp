#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, a, b;
vector<pii> tree[100001];
set<int> ax, bx;

void dfs(int cur, int parent, int dest, int x)
{
    if (cur == dest && dest == b)
        return;

    if (dest == b)
        ax.insert(x);
    else if (dest == a && parent != -1)
        bx.insert(x);

    for (const pii &p : tree[cur])
    {
        int nxt = p.first;
        int w = p.second;

        if (nxt != parent)
            dfs(nxt, cur, dest, x ^ w);
    }
}

void solve()
{
    cin >> n >> a >> b;

    for (int i = 1; i <= n; ++i)
        tree[i].clear();

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    ax.clear();
    bx.clear();
    dfs(a, -1, b, 0);
    dfs(b, -1, a, 0);

    for (int x : ax)
    {
        if (bx.find(x) != bx.end())
        {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

1
4 2 3
1 2 5
2 3 0
3 4 10

*/