#include <iostream>
#include <queue>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M, K;
char tilemap[1001][1001];
bool visited[11][1000][1000];

struct State
{
    int y, x, k, d;
    State(int _y, int _x, int _k, int _d) : y(_y), x(_x), k(_k), d(_d) {}
};

int bfs()
{
    queue<State> q;
    q.push(State(0, 0, K, 1));
    visited[K][0][0] = true;

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        if (cur.y == N - 1 && cur.x == M - 1)
            return cur.d;

        for (size_t i = 0; i < 4; i++)
        {
            int nxt_y = cur.y + dy[i];
            int nxt_x = cur.x + dx[i];
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                continue;

            if (tilemap[nxt_y][nxt_x] == '0' && !visited[cur.k][nxt_y][nxt_x])
            {
                visited[cur.k][nxt_y][nxt_x] = true;
                q.push(State(nxt_y, nxt_x, cur.k, cur.d + 1));
            }
            else if (tilemap[nxt_y][nxt_x] == '1' && cur.k > 0 && !visited[cur.k - 1][nxt_y][nxt_x])
            {
                visited[cur.k - 1][nxt_y][nxt_x] = true;
                q.push(State(nxt_y, nxt_x, cur.k - 1, cur.d + 1));
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