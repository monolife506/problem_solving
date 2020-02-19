// 2749번: 피보나치 수 3

#define MOD 1'000'000
#include <iostream>
#include <array>
using namespace std;

typedef unsigned long long ll;
typedef array<array<ll, 2>, 2> matrix;

matrix mat = {1, 1, 1, 0};

matrix matrix_multi(matrix A, matrix B)
{
    matrix result;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            ll sum = 0;
            for (size_t k = 0; k < 2; k++)
                sum = (((A[i][k] * B[k][j]) % MOD) + (sum % MOD)) % MOD;
            result[i][j] = sum;
        }
    }
    return result;
}

matrix matrix_mod(ll K)
{
    if (K == 1)
        return mat;

    matrix half = matrix_mod(K / 2);
    matrix result = matrix_multi(half, half);
    if (K % 2)
        result = matrix_multi(result, mat);
    return result;
}

int main()
{
    ll N;
    cin >> N;
    matrix ans = matrix_mod(N);
    cout << ans[0][1];
}
