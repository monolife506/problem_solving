#include <iostream>
#include <cstring>
using namespace std;

int x[1000], y[1000], dp[101][1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dp, -1, sizeof(dp));

    int N, M, A, B, C;
    cin >> N >> M >> A >> B >> C;
    for (int i = 0; i < N; ++i)
        cin >> x[i] >> y[i];

    dp[0][0][C] = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k <= A; ++k)
            {
                if (dp[i][j][k] == -1)
                    continue;

                dp[i + 1][j][max(0, k - B)] = max(dp[i + 1][j][max(0, k - B)], dp[i][j][k]);
                dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
                if (k + x[j] <= A)
                    dp[i + 1][j + 1][max(0, k + x[j] - B)] = max(dp[i + 1][j + 1][max(0, k + x[j] - B)], dp[i][j][k] + y[j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= M; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            for (int k = 0; k <= A; ++k)
                ans = max(ans, dp[i][j][k]);
        }
    }

    cout << ans << '\n';
}