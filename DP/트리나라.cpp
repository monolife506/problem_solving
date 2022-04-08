#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

vector<int> tree[51], child[51];
ll cache[51][51][51];

void dfs(int cur, int parent)
{
    for (int nxt : tree[cur])
    {
        if (nxt != parent)
        {
            child[cur].push_back(nxt);
            dfs(nxt, cur);
        }
    }
}

ll dp(int cur, int idx, int k)
{
    if (k == 0)
        return 1;
    if (idx >= child[cur].size())
        return (k == 1) ? 1 : 0;

    ll &ret = cache[cur][idx][k];
    if (ret != -1)
        return ret;

    int &nxt = child[cur][idx];
    int nxt_idx = child[nxt].size() - 1;
    if (idx == 0)
    {
        ret = dp(nxt, nxt_idx, k - 1);
        ret %= MOD;
    }
    else
    {
        ret = 0;
        for (int i = 1; i <= k; ++i)
        {
            ret += dp(cur, idx - 1, i) * dp(nxt, nxt_idx, k - i);
            ret %= MOD;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, K;
    cin >> N >> K;
    for (size_t i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(cache, -1, sizeof(cache));
    dfs(1, -1);

    ll ans = 0;
    for (size_t i = 1; i <= N; ++i)
    {
        ans += dp(i, child[i].size() - 1, K);
        ans %= MOD;
    }

    cout << ans << '\n';
}