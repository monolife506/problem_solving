#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 987654321;

ll dp[5001];

int main()
{
    int N;
    cin >> N;
    dp[0] = dp[1] = 1;
    for (size_t i = 2; i <= N / 2; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            dp[i] += (dp[j] % MOD) * (dp[i - (j + 1)] % MOD);
            dp[i] %= MOD;
        }
    }

    cout << dp[N / 2];
}

// 1
// 2
// 5
// 2 +