#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix;
const int MAX_N = 10;
const int MOD = 1000003;

int N, S, E, T;
int A[MAX_N][MAX_N];

Matrix matrixMulti(const Matrix &a, const Matrix &b)
{
    int n = a.size();
    Matrix ret(n, vector<ll>(n, 0));

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            for (size_t k = 0; k < n; k++)
                ret[i][j] = (((ret[i][j] % MOD) + (a[i][k] * b[k][j]) % MOD)) % MOD;

    return ret;
}

Matrix matrixPower(const Matrix &m, int k)
{
    if (k == 1)
        return m;

    Matrix half = matrixPower(m, k / 2);
    Matrix result = matrixMulti(half, half);
    return (k % 2 == 0) ? result : matrixMulti(result, m);
}

ll calculate()
{
    // dp에 사용될 행렬 만들기
    Matrix m(5 * N, vector<ll>(5 * N, 0));

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (A[i][j] <= 1)
            {
                m[5 * i][5 * j] = A[i][j];
                continue;
            }
            for (int k = 1; k < A[i][j]; k++)
            {
                m[5 * i + k - 1][5 * i + k] = 1;

                if (k + 1 == A[i][j])
                    m[5 * i + k][5 * j] = 1;
                else
                    m[5 * i + k][5 * i + k + 1] = 1;
            }
        }
    }

    // 실제 값 계산하기
    Matrix ans = matrixPower(m, T);
    return ans[5 * (S - 1)][5 * (E - 1)];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> E >> T;
    for (size_t i = 0; i < N; i++)
    {
        char buffer[MAX_N + 1];
        cin >> buffer;

        for (size_t j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            A[i][j] = buffer[j] - '0';
        }
    }

    cout << calculate() << '\n';
}