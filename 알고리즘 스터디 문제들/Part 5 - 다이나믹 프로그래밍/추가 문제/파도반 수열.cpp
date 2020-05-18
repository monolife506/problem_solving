#include <iostream>
#include <array>
using namespace std;
typedef unsigned long long ll;

array<ll, 101> dp;
int main()
{
    size_t T, N;
    cin >> T;

    dp[0] = 0;
    dp[1] = dp[2] = 1;
    for (size_t i = 3; i <= 100; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    for (size_t i = 0; i < T; i++)
    {
        cin >> N;
        cout << dp[N] << '\n';
    }
}