#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007;

int N, M;
ll dp[10001];

int main()
{
    cin >> N >> M;

    for (size_t i = 1; i < M; i++)
        dp[i] = 1;
    dp[M] = 2;
    for (size_t i = M + 1; i <= N; i++)
    {
        dp[i] = dp[i - 1];
        if (i - M > 0)
            dp[i] += dp[i - M];
        dp[i] %= MOD;
    }
    cout << dp[N];
}