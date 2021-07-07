#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;
constexpr ll MOD = 1'000'000'007;

mat mul(const mat& A, const mat& B)
{
    mat result = { { 0, 0 }, { 0, 0 } };
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 2; j++) {
            for (size_t k = 0; k < 2; k++) {
                result[i][j] = (((result[i][j] % MOD) + (A[i][k] * B[k][j]) % MOD)) % MOD;
            }
        }
    }

    return result;
}

mat pow(ll k, const mat& D)
{
    if (k == 1)
        return D;

    mat half = pow(k / 2, D);
    mat result = mul(half, half);
    return (k % 2 == 0) ? result : mul(result, D);
}

int main()
{
    ll n;
    cin >> n;

    mat D = { { 1, 1 }, { 1, 0 } };
    cout << pow(n, D)[0][1] << '\n';
}