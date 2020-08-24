// 11660번: 구간 합 구하기 5

#include <iostream>
using namespace std;

int dp[1025][1025];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t N, M;
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            int num;
            cin >> num;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + num;
        }
    }

    for (size_t i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - (dp[x2][y1 - 1] + dp[x1 - 1][y2] - dp[x1 - 1][y1 - 1]) << '\n';
    }
}