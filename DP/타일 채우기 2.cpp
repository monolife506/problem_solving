#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

const ll MOD = 1'000'000'007;

matrix multi(const matrix &A, const matrix &B)
{
    matrix ret(2, vector<ll>(2, 0));
    for (size_t i = 0; i < 2; ++i)
    {
        for (size_t j = 0; j < 2; ++j)
        {
            for (size_t k = 0; k < 2; ++k)
            {
                ret[i][j] += (A[i][k] * B[k][j] + MOD * MOD) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }

    return ret;
}

matrix pow(const matrix &A, ll K)
{
    if (K == 1)
        return A;

    matrix half = pow(A, K / 2);
    matrix ret = multi(half, half);
    return (K % 2 == 0) ? ret : multi(ret, A);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N;
    cin >> N;

    if (N % 2 == 0)
    {
        matrix mat = pow({{4, -1}, {1, 0}}, N / 2);
        cout << (mat[0][0] + mat[0][1] + MOD) % MOD << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}

/*

A[0] = 2
A[1] = 3
A[i] = A[i - 1] * 3 + A[i - 2] * 2 + A[i - 3] * 2 + ... + A[0] * 2 (i >= 2)

B[i] = A[i] + A[i - 1] + ... + A[0]
A[i] = B[i] - B[i - 1]

A[i] = A[i - 1] * 3 + B[i - 2] * 2
B[i] - B[i - 1] = (B[i - 1] - B[i - 2]) * 3 + B[i - 2] * 2
B[i] = B[i - 1] * 4 - B[i - 2] * 3 + B[i - 2] * 2 = B[i - 1] * 4 - B[i - 2]

*/