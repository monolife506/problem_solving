// 2206번: 벽 부수고 이동하기

#include <iostream>
#include <array>
#include <queue>
using namespace std;

struct Point
{
    bool breaked = false;
    int row;
    int col;
};

array<array<bool, 1000>, 1000> maze; // 미로

// visited[0] == 처음 미로의 시작점으로부터의 거리
// visited[1] == 벽을 부순 미로의 시작점으로부터의 거리
array<array<array<int, 1000>, 1000>, 2> visited;

array<int, 4> dx = {0, 0, -1, 1};
array<int, 4> dy = {1, -1, 0, 0};

void bfs(int N, int M)
{
    queue<Point> Q;
    Q.push({false, 0, 0});
    visited[0][0][0] = 1;

    while (!Q.empty())
    {
        Point cur = Q.front();
        Q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int row = cur.row + dy[i];
            int col = cur.col + dx[i];

            if (row < 0 || row >= N)
                continue;
            if (col < 0 || col >= M)
                continue;

            if (maze[row][col] && !cur.breaked && visited[true][row][col] == -1) // 벽인 경우
            {
                Q.push({true, row, col});
                visited[true][row][col] = visited[cur.breaked][cur.row][cur.col] + 1;
            }
            else if (!maze[row][col] && visited[cur.breaked][row][col] == -1) // 아닌 경우
            {
                Q.push({cur.breaked, row, col});
                visited[cur.breaked][row][col] = visited[cur.breaked][cur.row][cur.col] + 1;
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    char input[1001];
    for (size_t i = 0; i < N; i++)
    {
        cin >> input;
        for (size_t j = 0; j < M; j++)
            maze[i][j] = input[j] - '0';

        visited[0][i].fill(-1);
        visited[1][i].fill(-1);
    }

    bfs(N, M);

    if (visited[0][N - 1][M - 1] != -1 && visited[1][N - 1][M - 1] != -1)
        cout << min(visited[0][N - 1][M - 1], visited[1][N - 1][M - 1]);
    else if (visited[0][N - 1][M - 1] != -1)
        cout << visited[0][N - 1][M - 1];
    else if (visited[1][N - 1][M - 1] != -1)
        cout << visited[1][N - 1][M - 1];
    else
        cout << -1;
}
