#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000000;

ll dp[101][10][1 << 10]; // 길이, 끝 숫자, 하나라도 포함된 숫자들

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++)
        dp[1][i][1 << i] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < 1024; k++) {
                if (j > 0) {
                    int next = (k | (1 << (j - 1)));
                    dp[i + 1][j - 1][next] += dp[i][j][k];
                    dp[i + 1][j - 1][next] %= MOD;
                }
                if (j < 9) {
                    int next = (k | (1 << (j + 1)));
                    dp[i + 1][j + 1][next] += dp[i][j][k];
                    dp[i + 1][j + 1][next] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[N][i][1023];
        ans %= MOD;
    }

    cout << ans << '\n';
}