#include <iostream>
using namespace std;

int cache[2][15][15];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    int k_y = (K != 0) ? (K - 1) / M : N - 1;
    int k_x = (K != 0) ? (K - 1) % M : M - 1;

    cache[0][0][0] = 1;
    for (int i = 0; i <= k_y; ++i)
    {
        for (int j = 0; j <= k_x; ++j)
        {
            if (i != 0)
                cache[0][i][j] += cache[0][i - 1][j];
            if (j != 0)
                cache[0][i][j] += cache[0][i][j - 1];
        }
    }

    if (K != 0)
    {
        cache[1][k_y][k_x] = 1;
        for (int i = k_y; i <= N - 1; ++i)
        {
            for (int j = k_x; j <= M - 1; ++j)
            {
                if (i != k_y)
                    cache[1][i][j] += cache[1][i - 1][j];
                if (j != k_x)
                    cache[1][i][j] += cache[1][i][j - 1];
            }
        }

        cout << cache[0][k_y][k_x] * cache[1][N - 1][M - 1] << '\n';
    }
    else
    {
        cout << cache[0][N - 1][M - 1] << '\n';
    }
}