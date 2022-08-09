#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int R, C, dist[50][50];
char tilemap[51][51];

int bfs()
{
    static int dy[] = {-1, 0, 1, 0};
    static int dx[] = {0, 1, 0, -1};

    queue<pair<bool, P>> q;
    memset(dist, -1, sizeof(dist));

    P S, D;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (tilemap[i][j] == 'S')
                S = {i, j};
            else if (tilemap[i][j] == 'D')
                D = {i, j};
            else if (tilemap[i][j] == '*')
                q.push({false, {i, j}});
        }
    }

    q.push({true, S});
    dist[S.first][S.second] = 0;
    while (!q.empty())
    {
        bool is_hedgehog = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= R || nxt_x < 0 || nxt_x >= C)
                continue;
            if (is_hedgehog && tilemap[nxt_y][nxt_x] == '*')
                continue;
            if (!is_hedgehog && tilemap[nxt_y][nxt_x] == 'D')
                continue;
            if (tilemap[nxt_y][nxt_x] == 'X')
                continue;

            if (is_hedgehog && dist[nxt_y][nxt_x] == -1)
            {
                q.push({true, {nxt_y, nxt_x}});
                dist[nxt_y][nxt_x] = dist[y][x] + 1;
            }
            else if (!is_hedgehog && tilemap[nxt_y][nxt_x] != '*')
            {
                q.push({false, {nxt_y, nxt_x}});
                tilemap[nxt_y][nxt_x] = '*';
            }
        }
    }

    return dist[D.first][D.second];
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        cin >> tilemap[i];

    int ans = bfs();

    if (ans != -1)
        cout << ans << '\n';
    else
        cout << "KAKTUS" << '\n';
}