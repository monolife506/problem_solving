#include <iostream>
#include <array>
using namespace std;
typedef long long ll;

ll dp[91]; // dp[i] = i번째 피보나치 수

int main()
{
    // Base Case
    dp[0] = 0;
    dp[1] = 1;

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n] << '\n';
}