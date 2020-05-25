#include <iostream>
#include <array>
using namespace std;

array<int, 4> dx = {0, 0, -1, 1};
array<int, 4> dy = {1, -1, 0, 0};

int N, M;
int max_sum = 0; // 합의 최댓값
array<array<int, 501>, 501> board;
array<array<int, 501>, 501> visited = {};

// (a, b)로 위치, depth로 탐색 깊이를 나타내는 DFS
void dfs(int a, int b, int depth, int sum)
{
    if (depth == 4) // 깊이가 4이면 지금까지의 합과 최댓값을 비교한다.
    {
        max_sum = max(max_sum, sum);
        return;
    }

    for (size_t i = 0; i < 4; i++)
    {
        int y = a + dy[i];
        int x = b + dx[i];
        if (x < 0 || y < 0 || x >= M || y >= N)
            continue;

        if (!visited[y][x])
        {
            // 모든 경우를 탐색하기 위해서는 경로를 탐색한 직후 다시 방문 가능하게 하자.
            visited[y][x] = true;
            dfs(y, x, depth + 1, sum + board[y][x]);
            visited[y][x] = false;
        }
    }
}

// DFS로 계산 불가능한 테트로미노의 합 구하기
void cal()
{
    int sum;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (j != 0 && j != M - 1)
            {
                sum = board[i][j - 1] + board[i][j] + board[i][j + 1];
                if (i != 0) // ㅗ 모양
                    max_sum = max(max_sum, sum + board[i - 1][j]);
                if (i != N - 1) // ㅜ 모양
                    max_sum = max(max_sum, sum + board[i + 1][j]);
            }

            if (i != 0 && i != N - 1)
            {
                sum = board[i - 1][j] + board[i][j] + board[i + 1][j];
                if (j != 0) // ㅓ 모양
                    max_sum = max(max_sum, sum + board[i][j - 1]);
                if (j != M - 1) // ㅏ 모양
                    max_sum = max(max_sum, sum + board[i][j + 1]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
            cin >> board[i][j];
    }

    // DFS로 계산 가능한 테트로미노의 합 구하기
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;
        }
    }

    cal();
    cout << max_sum;
}