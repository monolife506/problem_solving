#include <deque>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;

int N, M, dist[100][100];
char maze[100][101];

int bfs()
{
    static int dy[] = {-1, 0, 1, 0};
    static int dx[] = {0, 1, 0, -1};

    fill_n(&dist[0][0], 100 * 100, INF);
    deque<P> dq;

    dist[0][0] = 0;
    dq.push_back({0, 0});

    while (!dq.empty())
    {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= M || nxt_x < 0 || nxt_x >= N)
                continue;

            int w = (maze[nxt_y][nxt_x] == '1');
            if (dist[nxt_y][nxt_x] > dist[y][x] + w)
            {
                dist[nxt_y][nxt_x] = dist[y][x] + w;
                (w == 1) ? dq.push_back({nxt_y, nxt_x})
                         : dq.push_front({nxt_y, nxt_x});
            }
        }
    }

    return dist[M - 1][N - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        cin >> maze[i];

    cout << bfs() << '\n';
}