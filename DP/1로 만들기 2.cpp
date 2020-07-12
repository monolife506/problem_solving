// 12852번: 1로 만들기 2

#include <iostream>
#include <cstring>
using namespace std;

int dp[3000001];
int pre[3000001];

int main()
{
    int N;
    cin >> N;

    memset(dp, -1, sizeof(dp));
    memset(pre, -1, sizeof(pre));

    dp[1] = 0;
    pre[1] = 0;
    for (int i = 1; i <= N; i++)
    {
        if ((dp[i + 1] != -1 && dp[i + 1] > dp[i] + 1) || (dp[i + 1] == -1))
        {
            dp[i + 1] = dp[i] + 1;
            pre[i + 1] = i;
        }
        if ((dp[i * 3] != -1 && dp[i * 3] > dp[i] + 1) || (dp[i * 3] == -1))
        {
            dp[i * 3] = dp[i] + 1;
            pre[i * 3] = i;
        }
        if ((dp[i * 2] != -1 && dp[i * 2] > dp[i] + 1) || (dp[i * 2] == -1))
        {
            dp[i * 2] = dp[i] + 1;
            pre[i * 2] = i;
        }
    }

    int cur = N;
    cout << dp[cur] << '\n';
    while (cur != 0)
    {
        cout << cur << " ";
        cur = pre[cur];
    }
}