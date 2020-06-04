#include <iostream>
#include <array>
#include <queue>
using namespace std;

array<array<bool, 101>, 101> maze;
array<array<int, 101>, 101> visited;

array<int, 4> dx = {0, 0, -1, 1};
array<int, 4> dy = {1, -1, 0, 0};

void bfs(size_t N, size_t M)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(1, 1));
    visited[1][1] = 1;

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        if (cur.second == M && cur.first == N)
            return;

        for (size_t i = 0; i < 4; i++)
        {
            int x = cur.second + dx[i];
            int y = cur.first + dy[i];

            if (x > M || x <= 0)
                continue;
            if (y > N || y <= 0)
                continue;
            if (visited[y][x] == -1 && maze[y][x])
            {
                Q.push(make_pair(y, x));
                visited[y][x] = visited[cur.first][cur.second] + 1;
            }
        }
    }
}

int main()
{
    size_t N, M;
    cin >> N >> M;

    char input[101];
    for (size_t i = 1; i <= N; i++)
    {
        cin >> input;
        for (size_t j = 1; j <= M; j++)
            maze[i][j] = input[j - 1] - '0';
        visited[i].fill(-1);
    }

    bfs(N, M);
    cout << visited[N][M];
}