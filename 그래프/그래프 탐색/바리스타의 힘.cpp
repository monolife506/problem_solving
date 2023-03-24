#include <iostream>
#include <queue>
using namespace std;

int N, M;
char maze[1001][1001];

struct State
{
    int p; // 0 ~ 3: 특정 방향으로 능력 사용중, 4/5: 능력 사용 가능/불가능
    int y, x;
    State(int p, int y, int x) : p(p), y(y), x(x) {}
};

int bfs()
{
    const int INF = 987654321;
    const int dy[] = {-1, 0, 1, 0};
    const int dx[] = {0, 1, 0, -1};

    static int dist[6][1001][1001];
    fill_n(&dist[0][0][0], 6 * 1001 * 1001, INF);

    queue<State> q;
    q.push(State(4, 0, 0));
    dist[4][0][0] = 0;

    while (!q.empty())
    {
        State cur = q.front();
        int &d = dist[cur.p][cur.y][cur.x];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nxt_y = cur.y + dy[i];
            int nxt_x = cur.x + dx[i];
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                continue;

            if (maze[nxt_y][nxt_x] == '0')
            {
                if (cur.p >= 0 && cur.p <= 3)
                {
                    if (i == cur.p && dist[cur.p][nxt_y][nxt_x] > d + 1) // 바리스타의 힘 사용중 (같은 방향)
                    {
                        dist[cur.p][nxt_y][nxt_x] = d + 1;
                        q.push(State(i, nxt_y, nxt_x));
                    }
                    if (i != cur.p && dist[5][nxt_y][nxt_x] > d + 1) // 바리스타의 힘 사용중 (다른 방향)
                    {
                        dist[5][nxt_y][nxt_x] = d + 1;
                        q.push(State(5, nxt_y, nxt_x));
                    }
                }
                else if (dist[cur.p][nxt_y][nxt_x] > d + 1) // 바리스타의 힘을 사용하지 않을 때
                {
                    dist[cur.p][nxt_y][nxt_x] = d + 1;
                    q.push(State(cur.p, nxt_y, nxt_x));
                }
            }
            else
            {
                if (cur.p == 4 && dist[i][nxt_y][nxt_x] > d + 1) // 바리스타의 힘 사용
                {
                    dist[i][nxt_y][nxt_x] = d + 1;
                    q.push(State(i, nxt_y, nxt_x));
                }
                if (i == cur.p && dist[cur.p][nxt_y][nxt_x] > d + 1) // 바리스타의 힘 사용중
                {
                    dist[cur.p][nxt_y][nxt_x] = d + 1;
                    q.push(State(i, nxt_y, nxt_x));
                }
            }
        }
    }

    int ret = INF;
    for (size_t i = 0; i < 6; i++)
        ret = min(ret, dist[i][N - 1][M - 1]);

    return ret != INF ? ret : -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
        cin >> maze[i];

    cout << bfs() << '\n';
}