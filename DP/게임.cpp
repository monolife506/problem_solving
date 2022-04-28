#include <iostream>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

char board[51][51];
int cache[50][50];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 50 * 50, -INF);

    size_t N, M;
    cin >> N >> M;
    for (size_t i = 0; i < N; ++i)
        cin >> board[i];

    cache[0][0] = 1;
    for (size_t i = 0; i < N * M; ++i)
    {
        for (size_t y = 0; y < N; ++y)
        {
            for (size_t x = 0; x < M; ++x)
            {
                if (board[y][x] == 'H')
                    continue;

                int num = board[y][x] - '0';
                for (size_t j = 0; j < 4; ++j)
                {
                    int nxt_y = y + num * dy[j];
                    int nxt_x = x + num * dx[j];
                    if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                        continue;
                    if (board[nxt_y][nxt_x] == 'H')
                        continue;

                    cache[nxt_y][nxt_x] = max(cache[nxt_y][nxt_x], cache[y][x] + 1);
                }
            }
        }
    }

    int ans = 0;
    for (size_t y = 0; y < N; ++y)
    {
        for (size_t x = 0; x < M; ++x)
            ans = max(ans, cache[y][x]);
    }

    cout << (ans <= N * M ? ans : -1) << '\n';
}