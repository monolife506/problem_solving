// 9465번: 스티커

#include <iostream>
#include <cstring>
using namespace std;

int num[2][100001];
int dp[100001][3]; // 0 == 선택 없음, 1 == 위쪽 선택, 2 == 아래쪽 선택

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;
        memset(dp, 0, sizeof(dp));

        for (size_t i = 1; i <= N; i++)
            cin >> num[0][i];
        for (size_t i = 1; i <= N; i++)
            cin >> num[1][i];

        for (size_t i = 1; i <= N; i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + num[0][i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + num[1][i];
        }

        cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << '\n';
    }
}