// 17070번: 파이프 옮기기 1
// 17069번: 파이프 옮기기 2

#include <iostream>
using namespace std;
typedef long long ll;

bool map[33][33];
ll dp[3][33][33]; // 1, 2, 3 -> 가로, 세로, 대각선

int main()
{
    int N;
    cin >> N;
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    dp[0][1][2] = 1;
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            if (!map[i][j]) // 가로 파이프
                dp[0][i][j] += dp[0][i][j - 1] + dp[2][i][j - 1];
            if (!map[i][j]) // 세로 파이프
                dp[1][i][j] += dp[1][i - 1][j] + dp[2][i - 1][j];
            if (!map[i][j] && !map[i - 1][j] && !map[i][j - 1]) // 대각선 파이프
                dp[2][i][j] += dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
        }
    }

    cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N];
}