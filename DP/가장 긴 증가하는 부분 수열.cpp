#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, A[1001], dp[1001];

int f(int cur)
{
    if (cur == 0)
        return 0;
    if (dp[cur] != -1)
        return dp[cur];

    dp[cur] = 0;
    for (int i = 0; i < cur; ++i)
    {
        if (A[i] < A[cur])
            dp[cur] = max(dp[cur], f(i) + 1);
    }

    return dp[cur];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, f(i));

    cout << ans << '\n';
}