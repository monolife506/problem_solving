#include <iostream>
using namespace std;

size_t n;
int amount[500][500], cache[500][500];

int dfs(int y, int x)
{
    static const int dy[4] = {-1, 0, 1, 0};
    static const int dx[4] = {0, 1, 0, -1};

    if (cache[y][x] != 0)
        return cache[y][x];

    cache[y][x] = 1;
    for (size_t i = 0; i < 4; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= n || nxt_x < 0 || nxt_x >= n)
            continue;
        if (amount[nxt_y][nxt_x] <= amount[y][x])
            continue;

        cache[y][x] = max(cache[y][x], dfs(nxt_y, nxt_x) + 1);
    }

    return cache[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
            cin >> amount[i][j];
    }

    int ans = 0;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
            ans = max(ans, dfs(i, j));
    }

    cout << ans << '\n';
}