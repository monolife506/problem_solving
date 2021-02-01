#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll dpA[1001][4][4];
ll dpB[1001][4][4];

int main()
{
    int N;
    cin >> N;

    dpA[1][0][0] = 1;
    dpB[1][0][0] = 1;
    for (size_t i = 2; i <= N; i++) {

        dpA[i][1][2] += dpA[i - 1][0][1];
        dpA[i][2][3] += dpA[i - 1][0][2];
        dpB[i][1][2] += dpB[i - 1][0][1];
        dpB[i][2][3] += dpB[i - 1][0][2];
        dpA[i][1][3] += dpA[i - 1][0][1];

        // 빈칸으로
        for (size_t j = 0; j < 4; j++) {

            dpA[i][0][1] += dpA[i - 1][j][0] % MOD;
            dpA[i][0][1] %= MOD;
            dpB[i][0][1] += dpB[i - 1][j][0] % MOD;
            dpB[i][0][1] %= MOD;
            dpA[i][0][2] += dpA[i - 1][j][0] % MOD;
            dpA[i][0][2] %= MOD;

            for (size_t k = 0; k < 4; k++) {
                dpA[i][k][0] += dpA[i - 1][j][k] % MOD;
                dpA[i][k][0] %= MOD;
                dpB[i][k][0] += dpB[i - 1][j][k] % MOD;
                dpB[i][k][0] %= MOD;
            }
        }
    }

    ll ansA = 0, ansB = 0;
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            ansA += dpA[N][i][j] % MOD;
            ansA %= MOD;
            ansB += dpB[N][i][j] % MOD;
            ansB %= MOD;
        }
    }

    if (((ansA - ansB) % MOD) < 0)
        cout << ((ansA - ansB) % MOD) + MOD;
    else
        cout << ((ansA - ansB) % MOD);
}