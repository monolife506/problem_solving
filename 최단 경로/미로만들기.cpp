#include <cstring>
#include <deque>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int n, dist[50][50];
char tilemap[51][51];

int bfs()
{
    const int INF = 987654321;
    const int dy[] = {-1, 0, 1, 0};
    const int dx[] = {0, 1, 0, -1};

    deque<P> dq;
    dq.push_back({0, 0});

    fill_n(&dist[0][0], 50 * 50, INF);
    dist[0][0] = 0;

    while (!dq.empty())
    {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();

        for (size_t i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= n || nxt_x < 0 || nxt_x >= n)
                continue;

            int d = (tilemap[nxt_y][nxt_x] == '0');
            if (dist[nxt_y][nxt_x] > dist[y][x] + d)
            {
                dist[nxt_y][nxt_x] = dist[y][x] + d;
                (d == 0) ? dq.push_front({nxt_y, nxt_x}) : dq.push_back({nxt_y, nxt_x});
            }
        }
    }

    return dist[n - 1][n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> tilemap[i];

    cout << bfs() << '\n';
}
