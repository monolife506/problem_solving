#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int N, M, before[30][30], after[30][30];
bool visited[30][30];

void bfs(P start)
{
    static const int dy[] = {-1, 0, 1, 0};
    static const int dx[] = {0, 1, 0, -1};

    queue<P> q;
    memset(visited, false, sizeof(visited));

    q.push(start);
    visited[start.first][start.second] = true;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                continue;
            if (before[y][x] != before[nxt_y][nxt_x])
                continue;

            if (!visited[nxt_y][nxt_x])
            {
                q.push({nxt_y, nxt_x});
                visited[nxt_y][nxt_x] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cin >> before[i][j];
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cin >> after[i][j];
    }

    bool flag = false;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            bfs({i, j});

            bool is_valid = true;
            for (int y = 0; y < N; ++y)
            {
                for (int x = 0; x < M; ++x)
                {
                    if (visited[y][x] && after[i][j] != after[y][x])
                        is_valid = false;
                    if (!visited[y][x] && before[y][x] != after[y][x])
                        is_valid = false;
                }
            }

            if (is_valid)
                flag = true;
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';
}