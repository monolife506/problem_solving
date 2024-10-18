#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

string x[500], y[2][500];
int dp[501][501][501];

void solve()
{
    int n, p, q;
    cin >> n >> p >> q;

    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < p; ++i)
        cin >> y[0][i];
    for (int i = 0; i < q; ++i)
        cin >> y[1][i];

    int ans = -1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= p; ++j)
        {
            for (int k = 0; k <= q; ++k)
            {
                dp[i][j][k] = dp[i - 1][j][k];

                if (j > 0)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + (x[i - 1] == y[0][j - 1]));
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
                }
                if (k > 0)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + (x[i - 1] == y[1][k - 1]));
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
                }

                ans = max(ans, dp[i][j][k]);
            }
        }
    }

    cout << ans << endl;
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