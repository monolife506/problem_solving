#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix;
const ll MOD = 1000000007;

Matrix operator*(const Matrix &lhs, const Matrix &rhs)
{
    int n = lhs.size();
    Matrix ret(n, vector<ll>(n, 0));

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            for (size_t k = 0; k < n; k++)
                ret[i][j] = (((ret[i][j] % MOD) + (lhs[i][k] * rhs[k][j]) % MOD)) % MOD;

    return ret;
}

Matrix matrixPower(const Matrix &m, int k)
{
    if (k == 1)
        return m;

    Matrix half = matrixPower(m, k / 2);
    Matrix ret = half * half;
    return (k % 2 == 0) ? ret : ret * m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, d;
    cin >> t >> n >> d;

    vector<Matrix> T(t, Matrix(n, vector<ll>(n, 0)));
    for (size_t i = 0; i < t; i++)
    {
        int m;
        cin >> m;
        for (size_t j = 0; j < m; j++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            T[i][a - 1][b - 1] = c;
        }
    }

    Matrix ans;
    if (d == 0)
    {
        ans = Matrix(n, vector<ll>(n, 0));
    }
    else if (d < t)
    {
        ans = T[0];
        for (int i = 1; i < d; i++)
            ans = ans * T[i];
    }
    else
    {
        Matrix tmp = T[0];
        for (int i = 1; i < t; i++)
            tmp = tmp * T[i];

        ans = matrixPower(tmp, d / t);
        for (int i = 0; i < d % t; i++)
            ans = ans * T[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
            cout << ans[i][j] << " ";

        cout << '\n';
    }
}

/*

0 ~ 1 : 0번
1 ~ 2 : 1 % T
2 ~ 3 : 2 % T 

*/