#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0, 0};
const int dx[] = {0, 1, 0, -1, 0};

int N, M, K;
bool visited[2][11][1000][1000];
char tilemap[1001][1001];

struct State
{
    int y, x, k, d;
    bool flag; // true: 낮, false: 밤
    State(int _y = 0, int _x = 0, int _k = 0, int _d = 0, bool _flag = false) : y(_y), x(_x), k(_k), d(_d), flag(_flag) {}
};

int bfs()
{
    queue<State> q;
    q.push(State(0, 0, K, 1, true));
    visited[true][K][0][0] = 1;

    while (!q.empty())
    {
        State cur = q.front();
        visited[cur.flag][cur.k][cur.y][cur.x] = true;
        q.pop();

        if (cur.y == N - 1 && cur.x == M - 1)
            return cur.d;

        for (size_t i = 0; i < 5; i++)
        {
            int nxt_y = cur.y + dy[i];
            int nxt_x = cur.x + dx[i];
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                continue;

            if (i == 4) // 가만히 있을 때
            {
                if (!visited[!cur.flag][cur.k][nxt_y][nxt_x])
                {
                    visited[!cur.flag][cur.k][nxt_y][nxt_x] = true;
                    q.push(State(nxt_y, nxt_x, cur.k, cur.d + 1, !cur.flag));
                }
                continue;
            }

            // 움직이는 경우
            if (tilemap[nxt_y][nxt_x] == '1' && cur.k > 0 && cur.flag)
            {
                if (!visited[!cur.flag][cur.k - 1][nxt_y][nxt_x])
                {
                    visited[!cur.flag][cur.k - 1][nxt_y][nxt_x] = true;
                    q.push(State(nxt_y, nxt_x, cur.k - 1, cur.d + 1, !cur.flag));
                }
            }
            else if (tilemap[nxt_y][nxt_x] == '0')
            {
                if (!visited[!cur.flag][cur.k][nxt_y][nxt_x])
                {
                    visited[!cur.flag][cur.k][nxt_y][nxt_x] = true;
                    q.push(State(nxt_y, nxt_x, cur.k, cur.d + 1, !cur.flag));
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for (size_t i = 0; i < N; i++)
        cin >> tilemap[i];

    cout << bfs() << '\n';
}
