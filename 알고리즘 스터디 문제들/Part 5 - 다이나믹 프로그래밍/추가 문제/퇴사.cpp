#include <iostream>
#include <array>
using namespace std;

// con[i].first == T[i + 1]
// con[i].second = P[i + 1]
array<pair<int, int>, 16> con;

// dp[i] == (i + 1)번째 날의 상담을 시작하기 전에 얻을 수 있는 최대 이익
array<int, 16> dp = {};

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> con[i].first >> con[i].second;
    con[N].first = con[N].second = 0;

    int ans = 0;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (j + con[j].first <= i && dp[j] + con[j].second > dp[i])
            {
                dp[i] = dp[j] + con[j].second;
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ans;
}