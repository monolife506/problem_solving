#include <iostream>
using namespace std;
typedef long long ll;

int U[3001], D[3001];
ll cache[2][3001][3001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0][0], 2 * 3001 * 3001, INT64_MAX);

    int N, M, L;
    cin >> N >> M >> L;
    for (int i = 1; i <= N; ++i)
        cin >> U[i];
    for (int i = 1; i <= M; ++i)
        cin >> D[i];

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            ll d = abs(U[i] - D[j]) * abs(U[i] - D[j]) + L * L;
            if (i == 1 && j == 1)
            {
                cache[0][i][j] = d * (N + M - 1);
                cache[1][i][j] = d * (i + j - 1) * (N + M - (i + j - 1));
            }
            if (i > 1) // D -> U
            {
                cache[0][i][j] = min(cache[0][i][j], cache[0][i - 1][j] + d * (N + M - 1));
                cache[1][i][j] = min(cache[1][i][j], cache[0][i - 1][j] + d * (i + j - 1) * (N + M - (i + j - 1)));
            }
            if (j > 1) // U -> D
            {
                cache[0][i][j] = min(cache[0][i][j], cache[1][i][j - 1] + d * (i + j - 1) * (N + M - (i + j - 1)));
                cache[1][i][j] = min(cache[1][i][j], cache[1][i][j - 1] + d * (N + M - 1));
            }
        }
    }

    cout << min(cache[0][N][M], cache[1][N][M]) << '\n';
}

/*

1   3   5
  2   4

*/