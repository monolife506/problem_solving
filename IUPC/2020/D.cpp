// 편집 거리 알고리즘
// https://madplay.github.io/post/levenshtein-distance-edit-distance

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX = 10000000;

bool wordcheck(char A, char B)
{
    bool isSame = false;
    if (A == B)
        isSame = true;
    else if (A == 'i' && (B == 'j' || B == 'l'))
        isSame = true;
    else if (A == 'v' && B == 'w')
        isSame = true;

    return isSame;
}

int main()
{
    int N, M;
    string A, B;
    cin >> N >> M >> A >> B;

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, MAX));
    for (size_t i = 0; i <= N; i++)
        dp[i][0] = i;
    for (size_t j = 0; j <= M; j++)
        dp[0][j] = j;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (wordcheck(A[i - 1], B[j - 1]))
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }

    cout << dp[N][M];
}
