#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000007;

ll dp[2][201][201];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int w, h, x, y;
    cin >> w >> h >> x >> y;

    for (size_t i = 1; i <= y; i++) {
        dp[0][i][1] = 1;
        for (size_t j = 2; j <= x; j++) {
            dp[0][i][j] = (dp[0][i - 1][j] % MOD) + (dp[0][i][j - 1] % MOD);
            dp[0][i][j] %= MOD;
        }
    }

    for (size_t i = y; i <= h; i++) {
        dp[1][i][x] = 1;
        for (size_t j = x + 1; j <= w; j++) {
            dp[1][i][j] = (dp[1][i - 1][j] % MOD) + (dp[1][i][j - 1] % MOD);
            dp[1][i][j] %= MOD;
        }
    }

    cout << ((dp[0][y][x] % MOD) * (dp[1][h][w] % MOD)) % MOD;
}