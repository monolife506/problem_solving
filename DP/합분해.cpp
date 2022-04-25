#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1e9;

ll cache[201][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, K;
    cin >> N >> K;
    for (size_t i = 0; i <= N; ++i)
        cache[1][i] = 1;

    for (size_t i = 2; i <= K; ++i)
    {
        for (size_t j = 0; j <= N; ++j)
        {
            for (size_t d = 0; d <= j; ++d)
            {
                cache[i][j] += cache[i - 1][j - d];
                cache[i][j] %= MOD;
            }
        }
    }

    cout << cache[K][N] << '\n';
}