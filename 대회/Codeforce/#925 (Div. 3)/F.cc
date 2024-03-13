#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int nth;
bool ans;

void dfs(int cur, vector<vector<int>> &graph, vector<int> &dfsn, vector<bool> &finished)
{
    dfsn[cur] = nth++;
    for (int nxt : graph[cur])
    {
        if (dfsn[nxt] == -1)
            dfs(nxt, graph, dfsn, finished);
        else if (dfsn[cur] > dfsn[nxt] && !finished[nxt])
            ans = false;
    }

    finished[cur] = true;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    set<pii> e;
    for (int i = 0; i < k; ++i)
    {
        vector<int> v(n);
        for (auto &vi : v)
            cin >> vi;
        for (int j = 2; j < n; ++j)
            e.insert({v[j - 1], v[j]});
    }

    vector<vector<int>> graph(n + 1);
    for (auto &[u, v] : e)
        graph[u].push_back(v);

    vector<int> dfsn(n + 1, -1);
    vector<bool> finished(n + 1, false);
    nth = 0;
    ans = true;
    for (int i = 1; i <= n; ++i)
    {
        if (dfsn[i] == -1)
            dfs(i, graph, dfsn, finished);
    }

    cout << (ans ? "YES" : "NO") << '\n';
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

3 -> 2

1 -> 3

2 -> 1


*/