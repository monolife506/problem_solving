#include <iostream>
#include <array>
using namespace std;

array<array<int, 500>, 500> num;
array<array<int, 500>, 500> dp;

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j <= i; j++)
            cin >> num[i][j];
    }

    int max_sum = dp[0][0] = num[0][0];
    for (size_t i = 1; i < N; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            if (j != 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);

            if (j != i)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            dp[i][j] += num[i][j];
            if (max_sum < dp[i][j])
                max_sum = dp[i][j];
        }
    }
    cout << max_sum;
}
