#include <iostream>
using namespace std;

char arr[1000][1000];
int cache[3][1000][1000]; // 0: 위쪽, 1: 왼쪽, 2: 왼쪽 위

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    for (size_t i = 0; i < n; ++i)
        cin >> arr[i];

    int ans = 0;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            if (arr[i][j] == '1')
            {
                cache[0][i][j] = (i != 0) ? cache[0][i - 1][j] + 1 : 1;
                cache[1][i][j] = (j != 0) ? cache[1][i][j - 1] + 1 : 1;
                cache[2][i][j] = (i != 0 && j != 0) ? cache[2][i - 1][j - 1] + 1 : 1;
                cache[2][i][j] = min(cache[2][i][j], min(cache[0][i][j], cache[1][i][j]));

                ans = max(ans, cache[2][i][j]);
            }
        }
    }

    cout << ans * ans << '\n';
}