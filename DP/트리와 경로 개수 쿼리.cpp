#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> tree[100001];
int a[100001], cnt[2], dp[2][100001];
ll ans[2][100001];

void dfs(int cur, int parent)
{
    for (int nxt : tree[cur])
    {
        if (nxt == parent)
            continue;

        dfs(nxt, cur);
        dp[0][cur] += dp[0][nxt];
        dp[1][cur] += dp[1][nxt];
    }

    for (int nxt : tree[cur])
    {
        if (nxt == parent)
            continue;

        ans[0][cur] += 1LL * dp[0][nxt] * (dp[1][cur] - dp[1][nxt]);
        ans[0][cur] += 1LL * dp[1][nxt] * (dp[0][cur] - dp[0][nxt]);
    }
    ans[0][cur] /= 2;

    if (a[cur] == 0)
    {
        ans[1][cur] += 1LL * dp[0][cur] * (cnt[1] - dp[1][cur]);
        ans[1][cur] += 1LL * dp[1][cur] * ((cnt[0] - 1) - dp[0][cur]);
    }
    else // a[cur] == 1
    {
        ans[1][cur] += 1LL * dp[0][cur] * ((cnt[1] - 1) - dp[1][cur]);
        ans[1][cur] += 1LL * dp[1][cur] * (cnt[0] - dp[0][cur]);
    }

    dp[a[cur]][cur]++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int u;
        cin >> u;
        cout << ans[0][u] + ans[1][u] << '\n';
    }
}
