// 2618번: 경찰차

#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

size_t N, W;
P events[1001];

int dp[1001][1001];
int preA[1001][1001];
int preB[1001][1001];

int dist(const P &A, const P &B)
{
    return abs(A.first - B.first) + abs(A.second - B.second);
}

void backtracking(int A, int B)
{
    if (A == B)
        return;

    backtracking(preA[A][B], preB[A][B]);
    if (A != preA[A][B])
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
}

int main()
{
    cin >> N >> W;
    for (size_t i = 1; i <= W; i++)
        cin >> events[i].first >> events[i].second;

    memset(dp, -1, sizeof(dp));
    P car1 = P(1, 1); // 경찰차 1 시작점
    P car2 = P(N, N); // 경찰차 2 시작점
    dp[1][0] = dist(car1, events[1]);
    dp[0][1] = dist(car2, events[1]);
    for (size_t i = 2; i <= W; i++)
    {
        for (size_t j = 0; j <= i - 2; j++)
        {
            // 1번 경찰차 이동
            if (dp[i][j] > dp[i - 1][j] + dist(events[i - 1], events[i]) || dp[i][j] == -1)
            {
                dp[i][j] = dp[i - 1][j] + dist(events[i - 1], events[i]);
                preA[i][j] = i - 1;
                preB[i][j] = j;
            }
            if (j == 0)
            {
                if (dp[i][i - 1] > dp[j][i - 1] + dist(car1, events[i]) || dp[i][i - 1] == -1)
                {
                    dp[i][i - 1] = dp[j][i - 1] + dist(car1, events[i]);
                    preA[i][i - 1] = j;
                    preB[i][i - 1] = i - 1;
                }
            }
            else
            {
                if (dp[i][i - 1] > dp[j][i - 1] + dist(events[j], events[i]) || dp[i][i - 1] == -1)
                {
                    dp[i][i - 1] = dp[j][i - 1] + dist(events[j], events[i]);
                    preA[i][i - 1] = j;
                    preB[i][i - 1] = i - 1;
                }
            }

            // 2번 경찰차 이동
            if (j == 0)
            {
                if (dp[i - 1][i] > dp[i - 1][j] + dist(car2, events[i]) || dp[i - 1][i] == -1)
                {
                    dp[i - 1][i] = dp[i - 1][j] + dist(car2, events[i]);
                    preA[i - 1][i] = i - 1;
                    preB[i - 1][i] = j;
                }
            }
            else
            {
                if (dp[i - 1][i] > dp[i - 1][j] + dist(events[j], events[i]) || dp[i - 1][i] == -1)
                {
                    dp[i - 1][i] = dp[i - 1][j] + dist(events[j], events[i]);
                    preA[i - 1][i] = i - 1;
                    preB[i - 1][i] = j;
                }
            }
            if (dp[j][i] > dp[j][i - 1] + dist(events[i - 1], events[i]) || dp[j][i] == -1)
            {
                dp[j][i] = dp[j][i - 1] + dist(events[i - 1], events[i]);
                preA[j][i] = j;
                preB[j][i] = i - 1;
            }
        }
    }

    int curA, curB, ans = INT32_MAX;
    for (size_t i = 0; i < W; i++)
    {
        if (ans > dp[W][i])
        {
            ans = dp[W][i];
            curA = W;
            curB = i;
        }
        if (ans > dp[i][W])
        {
            ans = dp[i][W];
            curA = i;
            curB = W;
        }
    }

    cout << ans << '\n';
    backtracking(curA, curB);
}

// 2
// 1 0
// 0 1

// 3
// 2 1
// 1 2
// 2 0
// 0 2

// 4
// 3 2
// 3 1
// 3 0
// 2 3
// 1 3
// 0 3

// 5
// 4 3
// 4 2
// 4 1
// 4 0
// 3 4
// 2 4
// 1 4
// 0 4

// N번째 사건이 벌어지면, 2(N - 1)번 탐색하여 최솟값 결정.