#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 1000;
const int MAX_M = 1000;
const int MAX_K = 10;
const int MOD = 1000000009;

int fj[MAX_N + 1], fp[MAX_M + 1];
ll cache[MAX_K + 1][MAX_N + 1][MAX_M + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M, K;
    cin >> N >> M >> K;
    for (size_t i = 1; i <= N; ++i)
        cin >> fj[i];
    for (size_t i = 1; i <= M; ++i)
        cin >> fp[i];

    for (size_t k = 1; k <= K; ++k)
    {
        for (size_t i = 1; i <= N; ++i)
        {
            for (size_t j = 1; j <= M; ++j)
            {
                if (fj[i] > fp[j])
                    cache[k][i][j] = (k == 1) ? 1 : cache[k - 1][i - 1][j - 1];
            }
        }
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                cache[k][i + 1][j + 1] += cache[k][i + 1][j];
                cache[k][i + 1][j + 1] += cache[k][i][j + 1];
                cache[k][i + 1][j + 1] -= cache[k][i][j];
                cache[k][i + 1][j + 1] += MOD;
                cache[k][i + 1][j + 1] %= MOD;
            }
        }
    }

    cout << cache[K][N][M] << '\n';
}