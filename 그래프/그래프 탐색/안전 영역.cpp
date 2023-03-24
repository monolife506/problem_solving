#include <cstring>
#include <iostream>
using namespace std;

int N, tilemap[100][100];
bool visited[100][100];

void dfs(int y, int x, int h)
{
    static int dy[] = {-1, 0, 1, 0};
    static int dx[] = {0, 1, 0, -1};

    visited[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= N)
            continue;
        if (tilemap[nxt_y][nxt_x] > h && !visited[nxt_y][nxt_x])
            dfs(nxt_y, nxt_x, h);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> tilemap[i][j];
    }

    int ans = 0;
    for (int h = 0; h <= 100; ++h)
    {
        memset(visited, false, sizeof(visited));

        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (tilemap[i][j] > h && !visited[i][j])
                {
                    dfs(i, j, h);
                    ++cnt;
                }
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}