// 11049번: 행렬 곱셈 순서
// 파일 합치기와 비슷한 아이디어.

#include <iostream>
#include <array>
using namespace std;

array<pair<int, int>, 501> mat;

// dp[i][j] == i번째부터 j번째까지의 행렬곱의 최소 연산수
array<array<int, 501>, 501> dp = {};

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> mat[i].first >> mat[i].second;

    for (size_t d = 1; d < N; d++)
    {
        for (size_t i = 0; i + d < N; i++)
        {
            dp[i][i + d] = INT32_MAX;
            for (size_t j = i; j < i + d; j++)
            {
                int sum = 0;
                sum += dp[i][j] + dp[j + 1][i + d];
                sum += mat[i].first * mat[j + 1].first * mat[i + d].second;

                dp[i][i + d] = min(sum, dp[i][i + d]);
            }
        }
    }

    cout << dp[0][N - 1];
}

// 1 2 3 4
// 1 (2 3 4)
// (1 2) (3 4)
// (1 2 3) 4