#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;
ll dp[11][11][11][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
        dp[i][0][0][1] = 1;

    for (int i = 2; i <= n; ++i) // 수열의 길이
    {
        // i > 1
        for (int x = 1; x <= m; ++x)
        {
            for (int y = 1; y <= m; ++y)
            {
                if (x >= y)
                {
                    dp[y][0][0][i] += dp[x][0][0][i - 1];
                    dp[y][0][0][i] %= MOD;
                }
                else // x < y
                {
                    dp[x][y][0][i] += dp[x][0][0][i - 1];
                    dp[x][y][0][i] %= MOD;
                }
            }
        }

        if (i > 2)
        {
            for (int x = 1; x <= m; ++x)
            {
                for (int y = 1; y <= m; ++y)
                {
                    for (int z = 1; z <= m; ++z)
                    {
                        if (x >= z)
                        {
                            dp[z][y][0][i] += dp[x][y][0][i - 1];
                            dp[z][y][0][i] %= MOD;
                        }
                        else if (x < z && z <= y)
                        {
                            dp[x][z][0][i] += dp[x][y][0][i - 1];
                            dp[x][z][0][i] %= MOD;
                        }
                        else // y < z
                        {
                            dp[x][y][z][i] += dp[x][y][0][i - 1];
                            dp[x][y][z][i] %= MOD;
                        }
                    }
                }
            }
        }

        if (i > 3)
        {
            for (int x = 1; x <= m; ++x)
            {
                for (int y = 1; y <= m; ++y)
                {
                    for (int z = 1; z <= m; ++z)
                    {
                        for (int w = 1; w <= z; ++w)
                        {
                            if (x >= w)
                            {
                                dp[w][y][z][i] += dp[x][y][z][i - 1];
                                dp[w][y][z][i] %= MOD;
                            }
                            else if (x < w && w <= y)
                            {
                                dp[x][w][z][i] += dp[x][y][z][i - 1];
                                dp[x][w][z][i] %= MOD;
                            }
                            else // y < w && w <= z
                            {
                                dp[x][y][w][i] += dp[x][y][z][i - 1];
                                dp[x][y][w][i] %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int x = 1; x <= m; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            for (int z = 1; z <= m; ++z)
            {
                ans += dp[x][y][z][n];
                ans %= MOD;
            }
        }
    }

    cout << ans << '\n';
}

/*

1 4 3 2 5 3

*/