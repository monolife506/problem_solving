// 17404번: RGB거리 2

#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1000000;

int N, ans = MAX;
int cost[1000][3];
int DP[1000][3];

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    for (size_t startColor = 0; startColor < 3; startColor++) // 첫 집의 색
    {
        memset(DP, MAX, sizeof(DP));
        DP[0][startColor] = cost[0][startColor];
        for (size_t i = 1; i < N; i++) // 집의 번호
        {
            for (size_t j = 0; j < 3; j++) // 전 집을 칠한 색
            {
                for (size_t k = 0; k < 3; k++) // 현재 집을 칠할 색
                {
                    if (j != k)
                    {
                        DP[i][k] = min(DP[i][k], DP[i - 1][j] + cost[i][k]);
                        if (i == N - 1 && k != startColor)
                            ans = min(ans, DP[i][k]);
                    }
                }
            }
        }
    }

    cout << ans;
}