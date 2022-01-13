#include <iostream>
#include <queue>
using namespace std;

const int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
typedef pair<int, int> P;

char maze[9][9];
bool visited[9][9][9];

bool bfs()
{
    queue<pair<P, int>> q;
    visited[8][0][8] = true;
    q.push(make_pair(P(8, 0), 8));

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int bottom = q.front().second;
        q.pop();

        for (size_t i = 0; i < 9; i++)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y > bottom || nxt_x < 0 || nxt_x > 8)
                continue;
            if (maze[nxt_y][nxt_x] == '#')
                continue;

            int nxt_bottom = max(bottom - 1, 0);
            if (nxt_y > 0)
                nxt_y--;

            if (maze[nxt_y][nxt_x] != '#' && !visited[nxt_bottom][nxt_y][nxt_x])
            {
                visited[nxt_bottom][nxt_y][nxt_x] = true;
                q.push(make_pair(P(nxt_y, nxt_x), nxt_bottom));
            }
        }
    }

    return visited[0][0][7];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill(maze[0], maze[0] + 8, '.');

    for (size_t i = 1; i <= 8; i++)
        cin >> maze[i];

    cout << bfs() << '\n';
}