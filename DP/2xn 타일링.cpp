// 11726번: 2xn 타일링

#include <iostream>
#include <array>
using namespace std;

array<int, 1001> dp;

int main()
{
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for (size_t i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] % 10007 + dp[i - 2] % 10007) % 10007;
    cout << dp[n];
}