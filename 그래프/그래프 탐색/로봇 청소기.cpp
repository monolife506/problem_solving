#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 20;
const int INF = 987654321;
typedef pair<int, int> P;

int w, h;
int room[MAX + 1][MAX + 1];
int dist[1 << 10][MAX + 1][MAX + 1];

char buffer[MAX + 1];

int bfs(P start, int dust_cnt)
{
    int ret = INF;
    const int dy[] = {1, -1, 0, 0};
    const int dx[] = {0, 0, 1, -1};

    for (size_t i = 0; i < (1 << dust_cnt); i++)
        for (size_t j = 0; j < h; j++)
            for (size_t k = 0; k < w; k++)
                dist[i][j][k] = INF;

    queue<pair<int, P>> q;
    q.push(make_pair(0, start));
    dist[0][start.first][start.second] = 0;

    while (!q.empty())
    {
        int mask = q.front().first;
        P cur = q.front().second;
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            P nxt = {cur.first + dy[i], cur.second + dx[i]};
            if (nxt.first < 0 || nxt.first >= h || nxt.second < 0 || nxt.second >= w)
                continue;

            int &nxt_chr = room[nxt.first][nxt.second];
            if (nxt_chr >= 0 && nxt_chr < dust_cnt)
            {
                int nxt_mask = mask | (1 << nxt_chr);
                if (dist[nxt_mask][nxt.first][nxt.second] > dist[mask][cur.first][cur.second] + 1)
                {
                    dist[nxt_mask][nxt.first][nxt.second] = dist[mask][cur.first][cur.second] + 1;
                    if (nxt_mask != (1 << dust_cnt) - 1)
                        q.push(make_pair(nxt_mask, nxt));
                    else
                        ret = min(ret, dist[nxt_mask][nxt.first][nxt.second]);
                }
            }
            else if (nxt_chr != 'x' && dist[mask][nxt.first][nxt.second] > dist[mask][cur.first][cur.second] + 1)
            {
                dist[mask][nxt.first][nxt.second] = dist[mask][cur.first][cur.second] + 1;
                q.push(make_pair(mask, nxt));
            }
        }
    }

    return (ret != INF) ? ret : -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> w >> h;
    while (w != 0 || h != 0)
    {
        P start;
        int dust_cnt = 0;

        for (size_t i = 0; i < h; i++)
        {
            cin >> buffer;
            for (size_t j = 0; j < w; j++)
            {
                room[i][j] = buffer[j];
                if (room[i][j] == '*')
                    room[i][j] = dust_cnt++;
                if (room[i][j] == 'o')
                    start = {i, j};
            }
        }

        cout << bfs(start, dust_cnt) << '\n';
        cin >> w >> h;
    }
}