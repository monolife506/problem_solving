// 2056번: 작업

#include <iostream>
#include <vector>
using namespace std;

int dp[10001];
int sec[10001];
vector<int> pre[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, cnt, num, maxTime, ans = 0;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> sec[i] >> cnt;
        for (size_t j = 0; j < cnt; j++)
        {
            cin >> num;
            pre[i].push_back(num);
        }
    }

    dp[1] = sec[1];
    for (size_t i = 2; i <= N; i++)
    {
        maxTime = 0;
        for (int &j : pre[i])
            maxTime = max(maxTime, dp[j]);

        dp[i] = maxTime + sec[i];
        ans = max(dp[i], ans);
    }

    cout << ans;
}

// 1
// 2 4
//