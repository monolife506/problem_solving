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
    if (T == 1) // 예외 케이스
        return (A[S - 1][E - 1] == 1);

    ll ret = 0;
    int node_cnt = N;
    int last_idx = N - 1;

    // 만들 행렬의 크기 먼저 계산하기
    for (size_t i = 0; i < N - 1; i++)
        for (size_t j = i + 1; j < N; j++)
            if (A[i][j] > 1)
                node_cnt += A[i][j] - 1;

    // dp에 사용될 행렬 만들기
    Matrix m(node_cnt, vector<ll>(node_cnt, 0));
    for (size_t i = 0; i < N - 1; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            if (A[i][j] <= 1)
            {
                m[i][j] = m[j][i] = A[i][j];
                continue;
            }

            for (int k = 0; k < A[i][j] - 1; k++)
            {
                last_idx++;

                if (k == 0)
                    m[i][last_idx] = m[last_idx][i] = 1;
                else
                    m[last_idx - 1][last_idx] = m[last_idx][last_idx - 1] = 1;

                if (k == A[i][j] - 2)
                    m[j][last_idx] = m[last_idx][j] = 1;
                else
                    m[last_idx + 1][last_idx] = m[last_idx][last_idx + 1] = 1;
            }
        }
    }

    // 실제 값 계산하기
    Matrix ans = matrixPower(m, T - 1);
    return ans[E - 1][S - 1];
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

/*

0
0
0
0


*/