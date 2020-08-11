// 11727번: 2xn 타일링 2

#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 10007;

ll dp[1001];

int main()
{
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 3;
    for (size_t i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] % MOD) + ((2 * dp[i - 2]) % MOD);
        dp[i] %= MOD;
    }
    cout << dp[n];
}