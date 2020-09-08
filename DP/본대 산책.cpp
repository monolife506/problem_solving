// 12849번: 본대 산책

#include <iostream>
using namespace std;

typedef long long ll;
constexpr int MOD = 1'000'000'007;

ll dp[8];
ll tmp[8];

int main()
{
    int D;
    cin >> D;

    dp[0] = 1;
    for (size_t i = 0; i < D; i++)
    {
        tmp[0] = dp[1] + dp[7];
        tmp[1] = dp[0] + dp[2] + dp[7];
        tmp[2] = dp[1] + dp[3] + dp[6] + dp[7];
        tmp[3] = dp[2] + dp[4] + dp[6];
        tmp[4] = dp[3] + dp[5];
        tmp[5] = dp[4] + dp[6];
        tmp[6] = dp[2] + dp[3] + dp[5] + dp[7];
        tmp[7] = dp[0] + dp[1] + dp[2] + dp[6];

        for (size_t i = 0; i < 8; i++)
            dp[i] = tmp[i] % MOD;
    }

    cout << dp[0];
}

// 0 : 1 7
// 1 : 0 2 7
// 2 : 1 3 6 7
// 3 : 2 4 6
// 4 : 3 5
// 5 : 4 6
// 6 : 2 3 5 7
// 7 : 0 1 2 6