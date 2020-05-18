#include <iostream>
#include <array>
using namespace std;

array<int, 1001> A;
array<int, 1001> dp;

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
        cin >> A[i];

    int max_sum = 0;
    for (size_t i = 0; i <= N - 1; i++)
    {
        for (size_t j = i + 1; j <= N; j++)
        {
            if (A[j] > A[i] && dp[i] + A[j] > dp[j])
            {
                dp[j] = dp[i] + A[j];
                max_sum = max(max_sum, dp[j]);
            }
        }
    }
    cout << max_sum;
}