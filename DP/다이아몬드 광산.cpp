#include <iostream>
using namespace std;

char mine[751][751];
int cache[4][750][750];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        cin >> mine[i];

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (mine[i][j] != '1')
                continue;

            cache[2][i][j] = (i > 0 && j > 0) ? cache[2][i - 1][j - 1] + 1 : 1;
            cache[3][i][j] = (i > 0 && j < C - 1) ? cache[3][i - 1][j + 1] + 1 : 1;
        }
    }
    for (int i = R - 1; i >= 0; --i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (mine[i][j] != '1')
                continue;

            cache[0][i][j] = (i < R - 1 && j > 0) ? cache[0][i + 1][j - 1] + 1 : 1;
            cache[1][i][j] = (i < R - 1 && j < C - 1) ? cache[1][i + 1][j + 1] + 1 : 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            int max_k = min(cache[0][i][j], cache[1][i][j]);
            for (int k = 1; k <= max_k; ++k)
            {
                if (i + (k - 1) * 2 >= R)
                    continue;
                if (k <= min(cache[2][i + (k - 1) * 2][j], cache[3][i + (k - 1) * 2][j]))
                    ans = max(ans, k);
            }
        }
    }

    cout << ans << '\n';
}