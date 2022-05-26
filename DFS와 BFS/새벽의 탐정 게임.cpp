#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M, dist[6][500][500];
char tilemap[501][501];

int bfs(P start, P dest)
{
    queue<pair<P, int>> q;
    q.push({start, 4});

    fill_n(&dist[0][0][0], 6 * 500 * 500, INF);
    dist[4][start.first][start.second] = 0;

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int d = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];

            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                continue;
            if (tilemap[nxt_y][nxt_x] == '#')
                continue;

            int nxt_d;
            if (d >= 0 && d <= 3)
            {
                if (d == (i + 1) % 4 || d == (i + 3) % 4)
                    nxt_d = d;
                else
                    nxt_d = (d == i) ? 4 : 5;
            }
            else if (d == 4)
            {
                nxt_d = (i + 2) % 4;
            }
            else // nxt_d == 5
            {
                nxt_d = i;
            }

            if (tilemap[nxt_y][nxt_x] == 'R' && nxt_d != 4)
                continue;

            if (dist[nxt_d][nxt_y][nxt_x] > dist[d][y][x] + 1)
            {
                q.push({{nxt_y, nxt_x}, nxt_d});
                dist[nxt_d][nxt_y][nxt_x] = dist[d][y][x] + 1;
            }
        }
    }

    int ans = dist[4][dest.first][dest.second];
    return (ans != INF) ? ans : -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    P start, dest;

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> tilemap[i];
        for (int j = 0; j < M; ++j)
        {
            if (tilemap[i][j] == 'D')
                start = {i, j};
            else if (tilemap[i][j] == 'R')
                dest = {i, j};
        }
    }

    cout << bfs(start, dest) << '\n';
}