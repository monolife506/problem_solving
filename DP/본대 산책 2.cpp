#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll MOD = 1000000007;

matrix arr, ans;

matrix multi(const matrix& A, const matrix& B)
{
    matrix result(8, vector<ll>(8, 0));
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            for (size_t k = 0; k < 8; k++)
                result[i][j] = (((result[i][j] % MOD) + (A[i][k] * B[k][j]) % MOD)) % MOD;
        }
    }
    return result;
}

matrix pow(ll K)
{
    if (K == 1)
        return arr;

    matrix half = pow(K / 2);
    matrix result = multi(half, half);
    return (K % 2 == 0) ? result : multi(result, arr);
}

int main()
{
    int D;
    cin >> D;

    arr.resize(8, vector<ll>(8, 0));
    arr[0][1] = arr[0][7] = 1;
    arr[1][0] = arr[1][2] = arr[1][7] = 1;
    arr[2][1] = arr[2][3] = arr[2][6] = arr[2][7] = 1;
    arr[3][2] = arr[3][4] = arr[3][6] = 1;
    arr[4][3] = arr[4][5] = 1;
    arr[5][4] = arr[5][6] = 1;
    arr[6][2] = arr[6][3] = arr[6][5] = arr[6][7] = 1;
    arr[7][0] = arr[7][1] = arr[7][2] = arr[7][6] = 1;

    if (D == 1) {
        cout << 0 << '\n';
        return 0;
    }

    matrix ans = pow(D - 1);
    cout << (ans[1][0] + ans[7][0]) % MOD << '\n';
}

/*

기본 행렬 (A[i])
dp[i][0]
dp[i][1]
dp[i][2]
dp[i][3]
dp[i][4]
dp[i][5]
dp[i][6]
dp[i][7]

곱할 행렬 (B)
0 1 0 0 0 0 0 1
1 0 1 0 0 0 0 1
0 1 0 1 0 0 1 1
0 0 1 0 1 0 1 0
0 0 0 1 0 1 0 0
0 0 0 0 1 0 1 0
0 0 1 1 0 1 0 1
1 1 1 0 0 0 1 0

A[i] * B = A[i + 1]
A[0] * B^D = A[D]

*/