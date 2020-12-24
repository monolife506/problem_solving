#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;
typedef vector<vector<ll>> matrix;

const ll MOD = 1'000'000'007;

ll N, M;
matrix mat, ans;

matrix multi(const matrix &A, const matrix &B)
{
    matrix result(M, vector<ll>(M, 0));
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            for (size_t k = 0; k < M; k++)
                result[i][j] = (((result[i][j] % MOD) + (A[i][k] * B[k][j]) % MOD)) % MOD;
        }
    }
    return result;
}

matrix pow(ll K)
{
    if (K == 1)
        return mat;

    matrix half = pow(K / 2);
    matrix result = multi(half, half);
    return (K % 2 == 0) ? result : multi(result, mat);
}

int main()
{
    cin >> N >> M;

    mat.resize(M, vector<ll>(M, 0));
    mat[0][0] = mat[0][M - 1] = 1;
    for (size_t i = 1; i < M; i++)
        mat[i][i - 1] = 1;

    ans = pow(N);
    cout << ans[0][0];
}

/*
dp[i] = dp[i - 1] + dp[i - M]
*/
