#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int N, M, dist[50][50];
char tilemap[51][51];

int bfs(P S)
{
    static int dy[] = {-1, 0, 1, 0};
    static int dx[] = {0, 1, 0, -1};

    queue<P> q;
    memset(dist, -1, sizeof(dist));

    q.push(S);
    dist[S.first][S.second] = 0;

    int ret = 0;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        ret = max(ret, dist[y][x]);

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                continue;
            if (tilemap[nxt_y][nxt_x] == 'W')
                continue;

            if (dist[nxt_y][nxt_x] == -1)
            {
                dist[nxt_y][nxt_x] = dist[y][x] + 1;
                q.push({nxt_y, nxt_x});
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> tilemap[i];

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (tilemap[i][j] == 'L')
                ans = max(ans, bfs({i, j}));
        }
    }

    cout << ans << '\n';
}