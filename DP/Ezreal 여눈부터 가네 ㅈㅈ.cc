#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 1'000'000'007;

ll dp[3][1515];

void solve()
{
    int n;
    cin >> n;

    dp[1][1] = dp[2][1] = 1;
    for (int i = 2; i < n; ++i)
    {
        dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % MOD;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
        dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
    }

    cout << dp[1][n - 1] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}