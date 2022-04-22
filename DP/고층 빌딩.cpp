#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll cache[101][101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, L, R;
    cin >> N >> L >> R;

    cache[1][1][1] = 1;
    for (size_t n = 1; n < N; ++n)
    {
        for (size_t l = 1; l <= L; ++l)
        {
            for (size_t r = 1; r <= R; ++r)
            {
                // 중간
                cache[n + 1][l][r] += (n - 1) * cache[n][l][r];
                cache[n + 1][l][r] %= MOD;
                // 왼쪽 끝
                cache[n + 1][l + 1][r] += cache[n][l][r];
                cache[n + 1][l + 1][r] %= MOD;
                // 오른쪽 끝
                cache[n + 1][l][r + 1] += cache[n][l][r];
                cache[n + 1][l][r + 1] %= MOD;
            }
        }
    }

    cout << cache[N][L][R] << '\n';
}