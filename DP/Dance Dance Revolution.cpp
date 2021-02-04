#include <iostream>
using namespace std;
const int MAX = 987654321;

int N = 0;
int act[100002];
int dp[100002][5][5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    do
    {
        cin >> act[++N];
    } while (act[N] != 0);

    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < 5; j++)
            for (size_t k = 0; k < 5; k++)
                dp[i][j][k] = MAX;

    dp[0][0][0] = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (act[i] == j || act[i] == k)
                {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 1);
                    continue;
                }

                if (j == 0)
                    dp[i][act[i]][k] = min(dp[i][act[i]][k], dp[i - 1][j][k] + 2);
                else if (abs(act[i] - j) != 2)
                    dp[i][act[i]][k] = min(dp[i][act[i]][k], dp[i - 1][j][k] + 3);
                else
                    dp[i][act[i]][k] = min(dp[i][act[i]][k], dp[i - 1][j][k] + 4);

                if (k == 0)
                    dp[i][j][act[i]] = min(dp[i][j][act[i]], dp[i - 1][j][k] + 2);
                else if (abs(act[i] - k) != 2)
                    dp[i][j][act[i]] = min(dp[i][j][act[i]], dp[i - 1][j][k] + 3);
                else
                    dp[i][j][act[i]] = min(dp[i][j][act[i]], dp[i - 1][j][k] + 4);
            }
        }
    }

    int ans = MAX;
    for (size_t j = 0; j < 5; j++)
        for (size_t k = 0; k < 5; k++)
            ans = min(ans, dp[N - 1][j][k]);
    cout << ans;
}