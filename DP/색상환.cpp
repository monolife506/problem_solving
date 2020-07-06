// 2482번: 색상환

#include <iostream>
using namespace std;
const int MOD = 1000000003;

// DP[N][K] == N개의 색상환에서 K개를 이웃하지 않게 택하는 경우의 수
int DP[1001][1001];

int main()
{
    int N, K;
    cin >> N >> K;

    DP[2][1] = 2;
    DP[3][1] = 3;
    for (size_t i = 4; i <= N; i++)
    {
        for (size_t j = 1; j <= N / 2; j++)
        {
            if (j == 1)
                DP[i][j] = i;
            else
            {
                DP[i][j] = (DP[i - 1][j] % MOD) + (DP[i - 2][j - 1] % MOD);
                DP[i][j] %= MOD;
            }
        }
    }
    cout << DP[N][K];
}

// 4 => 5
// 0 1 1 0 1 + 1 1 1 1 0
// => + DP[]