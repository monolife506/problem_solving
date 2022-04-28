#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

ll cache[61][31][31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    while (N != 0)
    {
        memset(cache, 0, sizeof(cache));

        cache[0][N][0] = 1;
        for (size_t i = 0; i < 2 * N; ++i)
        {
            for (size_t j = 0; j <= N; ++j)
            {
                for (size_t k = 0; k <= N; ++k)
                {
                    if (j > 0)
                        cache[i + 1][j - 1][k + 1] += cache[i][j][k];
                    if (k > 0)
                        cache[i + 1][j][k - 1] += cache[i][j][k];
                }
            }
        }

        ll ans = 0;
        for (size_t j = 0; j <= N; ++j)
        {
            for (size_t k = 0; k <= N; ++k)
                ans += cache[2 * N][j][k];
        }
        cout << ans << '\n';

        cin >> N;
    }
}