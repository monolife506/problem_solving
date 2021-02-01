#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int H[101];
int dp[101][501];
vector<int> graph[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));

    int N, M, T;
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++) {
        cin >> H[i];
        dp[i][0] = H[i];
    }
    for (size_t i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }

    for (size_t k = 1; k <= 500; k++) {
        for (size_t i = 1; i <= N; i++) {
            for (int before : graph[i]) {
                if (dp[before][k - 1] != -1) {
                    if (dp[i][k] == -1) {
                        dp[i][k] = dp[before][k - 1];
                        continue;
                    }

                    dp[i][k] = min(dp[i][k], dp[before][k - 1]);
                }
            }
        }
    }

    cin >> T;
    for (size_t i = 0; i < T; i++) {
        int A, K;
        cin >> A >> K;
        cout << dp[A][K] << '\n';
    }
}