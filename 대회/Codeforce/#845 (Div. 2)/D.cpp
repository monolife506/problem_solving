#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1'000'000'007;

ll mod_2n[200001];

void precompute()
{
    mod_2n[0] = 1;
    for (int i = 1; i <= 200'000; ++i)
        mod_2n[i] = (mod_2n[i - 1] * 2) % MOD;
}

void dfs(int cur, int parent, vector<vector<int>> &tree, vector<int> &t)
{
    if (parent != -1 && tree[cur].size() == 1)
    {
        t[cur] = 1;
        return;
    }

    for (int nxt : tree[cur])
    {
        if (nxt == parent)
            continue;

        dfs(nxt, cur, tree, t);
        t[cur] = max(t[cur], t[nxt] + 1);
    }
}

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }

    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> t(n + 1, -1);
    dfs(1, -1, tree, t);

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += mod_2n[n - 1] * t[i];
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}