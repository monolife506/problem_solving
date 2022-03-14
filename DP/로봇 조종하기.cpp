#include <iostream>
using namespace std;

int value[1000][1000], cache[2][1000][1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0][0], 2 * 1000 * 1000, -987654321);

    size_t n, m;
    cin >> n >> m;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
            cin >> value[i][j];
    }

    cache[0][0][0] = value[0][0];
    for (size_t j = 1; j < m; ++j)
        cache[0][0][j] = cache[0][0][j - 1] + value[0][j];

    if (n >= 3)
    {
        for (size_t i = 1; i < n - 1; ++i)
        {
            cache[0][i][0] = max(cache[0][i - 1][0], cache[1][i - 1][0]) + value[i][0];
            cache[1][i][m - 1] = max(cache[0][i - 1][m - 1], cache[1][i - 1][m - 1]) + value[i][m - 1];
            for (int j = 1; j < m; ++j)
            {
                int upper_value = max(cache[0][i - 1][j], cache[1][i - 1][j]);
                int left_value = cache[0][i][j - 1];
                cache[0][i][j] = max(upper_value, left_value) + value[i][j];
            }
            for (int j = m - 2; j >= 0; --j)
            {
                int upper_value = max(cache[0][i - 1][j], cache[1][i - 1][j]);
                int right_value = cache[1][i][j + 1];
                cache[1][i][j] = max(upper_value, right_value) + value[i][j];
            }
        }
    }
    if (n >= 2)
    {
        cache[0][n - 1][0] = max(cache[0][n - 2][0], cache[1][n - 2][0]) + value[n - 1][0];
        for (size_t j = 1; j < m; ++j)
        {
            int upper_value = max(cache[0][n - 2][j], cache[1][n - 2][j]);
            int left_value = cache[0][n - 1][j - 1];
            cache[0][n - 1][j] = max(upper_value, left_value) + value[n - 1][j];
        }
    }

    cout << cache[0][n - 1][m - 1] << '\n';
}