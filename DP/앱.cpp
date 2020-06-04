// 7579번: 앱
// 냅색 문제의 변형 ("가치의 최소 합" 구하기)
// M바이트 이상을 확보해야 한다는 것이 중요하다.

#include <iostream>
#include <array>
using namespace std;

// app[i].first == i번째 앱의 메모리
// app[i].second == i번째 앱을 비활성화 할 때의 비용
array<pair<int, int>, 101> app;

// dp[i][j] == i번째 물건까지 탐색했을 때의 가치의 합이 j인 경우 최대 M
array<array<int, 10001>, 101> dp = {};

int main()
{
    int N, M;
    int max_cost = 0;
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
        cin >> app[i].first;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> app[i].second;
        max_cost += app[i].second;
    }

    int ans = INT32_MAX;
    for (size_t i = 1; i <= N; i++)
    {
        for (int j = 0; j <= max_cost; j++)
        {
            if (app[i].second > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - app[i].second] + app[i].first);

            if (dp[i][j] >= M)
                ans = min(ans, j);
        }
    }
    cout << ans;
}