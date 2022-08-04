#include <cstring>
#include <iostream>
using namespace std;

int w, h;
bool tilemap[50][50], visited[50][50];

void dfs(int y, int x)
{
    static int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

    visited[y][x] = true;
    for (int i = 0; i < 8; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= h || nxt_x < 0 || nxt_x >= w)
            continue;
        if (tilemap[nxt_y][nxt_x] && !visited[nxt_y][nxt_x])
            dfs(nxt_y, nxt_x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> w >> h;
    while (w != 0 && h != 0)
    {
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
                cin >> tilemap[i][j];
        }

        int ans = 0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (tilemap[i][j] && !visited[i][j])
                {
                    ++ans;
                    dfs(i, j);
                }
            }
        }

        cout << ans << '\n';

        cin >> w >> h;
    }
}