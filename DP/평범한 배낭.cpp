// 12865번: 평범한 배낭

#include <iostream>
#include <array>
using namespace std;

// W[i] == i번째 물건의 무게
array<int, 100> W;
// V[i] == i번째 물건의 가치
array<int, 100> V;

// used[i][j] == 무게의 합이 i일 때 j번째의 물건을 가방에 넣었는가?
array<array<bool, 100>, 100001> used = {};
// dp[i] == 무게의 합이 i일 때 최대 가치합
array<int, 100001> dp = {};

int main()
{
    int N, K;
    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
        cin >> W[i] >> V[i];

    int max_val = 0;
    for (size_t i = 0; i <= K; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            int target_w = i + W[j];
            if (K >= target_w)
            {
                if (!used[i][j] && dp[target_w] < dp[i] + V[j])
                {
                    dp[target_w] = dp[i] + V[j];
                    used[target_w] = used[i];
                    used[target_w][j] = true;

                    max_val = max(max_val, dp[target_w]);
                }
            }
        }
    }
    cout << max_val;
}