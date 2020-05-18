#include <iostream>
#include <array>
using namespace std;

// W[i] == i번째 물건의 무게
array<int, 100> W = {};
// V[i] == i번째 물건의 가치
array<int, 100> V = {};

// dp[i][j] == i번째 물건까지 탐색했을 때 무게가 j인 경우 최대 가치합
array<array<int, 100001>, 101> dp;

int main()
{
    int N, K;
    cin >> N >> K;
    for (size_t i = 1; i <= N; i++)
        cin >> W[i] >> V[i];

    int max_val = 0;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= K; j++)
        {
            if (W[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);

            max_val = max(max_val, dp[i][j]);
        }
    }
    cout << max_val;
}
