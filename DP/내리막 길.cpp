// 1520번: 내리막길
// DFS BFS 순간 까먹어서 뇌정지오지 말자.

#include <iostream>
#include <array>
#include <stack>
using namespace std;

size_t M, N;
array<array<int, 501>, 501> map;
array<array<int, 501>, 501> dp; // 어떤 점에서 목적지로 향하는 경로의 수

void dfs(int x, int y)
{
    static array<int, 4> dx = {0, 0, -1, 1};
    static array<int, 4> dy = {1, -1, 0, 0};

    if (dp[y][x] == -1)
        dp[y][x] = 0;

    for (size_t i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if (map[ny][nx] < map[y][x])
        {
            if (dp[ny][nx] == -1)
                dfs(nx, ny);
            dp[y][x] += dp[ny][nx];
        }
    }
}

int main()
{
    cin >> M >> N;
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            dp[i][j] = -1;
            cin >> map[i][j];
        }
    }

    dp[M - 1][N - 1] = 1;
    dfs(0, 0);
    cout << dp[0][0];
}