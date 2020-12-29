#include <iostream>
using namespace std;
const int MAX = 200;

int dp[101][21];
bool isEmpty[101][21];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K, M, H;
    cin >> N >> K;
    for (size_t i = 1; i <= N; i++) {
        cin >> M;
        for (size_t j = 0; j < M; j++) {
            cin >> H;
            isEmpty[i][H] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 20; j++) {
            dp[i][j] = MAX;
        }
    }

    dp[0][1] = 0;
    isEmpty[0][1] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 20; j++) {
            for (int k = 1; k <= 20; k++) {
                if (isEmpty[i - 1][j] && isEmpty[i][k]) {
                    if ((j - 1 <= k && j + 1 >= k) || min(j * 2, 20) == k)
                        dp[i][k] = min(dp[i][k], dp[i - 1][j]);
                    else
                        dp[i][k] = min(dp[i][k], dp[i - 1][j] + 1);
                }
            }
        }
    }

    int ans = MAX;
    bool flag = false;
    for (size_t i = 1; i <= 20; i++) {
        if (dp[N][i] <= K) {
            ans = min(ans, dp[N][i]);
            flag = true;
        }
    }
    cout << ((flag) ? ans : -1);
}