#include <iostream>
using namespace std;

int dp[301][301];

int main() {
    int N, num, ans = -1000;
    cin >> N;

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            
            cin >> num;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + num;

            int K = min(i, j);
            for (size_t k = 0; k < K; k++)
            {
                int I = i - k;
                int J = j - k;
                int total = dp[i][j] - (dp[i][J - 1] + dp[I - 1][j] - dp[I - 1][J - 1]);
                ans = max(ans, total);
            }
        } 
    }

    cout << ans;
} 