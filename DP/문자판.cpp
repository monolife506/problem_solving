#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int N, M, K;
char board[101][101];
string word;

int cache[81][101][101];

int solve(int y, int x, int idx)
{
    static const int dy[] = {-1, 0, 1, 0};
    static const int dx[] = {0, 1, 0, -1};

    if (idx == 0)
        return 1;
    if (cache[idx][y][x] != -1)
        return cache[idx][y][x];

    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int k = 1; k <= K; k++)
        {
            int nxt_y = y + k * dy[i];
            int nxt_x = x + k * dx[i];
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                continue;
            if (board[nxt_y][nxt_x] == word[idx - 1])
                ret += solve(nxt_y, nxt_x, idx - 1);
        }
    }

    return cache[idx][y][x] = ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for (size_t i = 0; i < N; i++)
        cin >> board[i];

    cin >> word;

    int ans = 0;
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < M; j++)
            if (board[i][j] == word.back())
                ans += solve(i, j, word.size() - 1);

    cout << ans << '\n';
}