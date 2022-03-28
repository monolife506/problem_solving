#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int dy[] = {-1, 0, 1, 1, 0, -1};
const int dx[] = {1, 1, 1, -1, -1, -1};

int N, M;
char tilemap[81][81];

P matched[80][80];
bool visited[80][80];

bool match(P cur)
{
    int &y = cur.first;
    int &x = cur.second;
    if (visited[y][x])
        return false;

    visited[y][x] = true;
    for (size_t i = 0; i < 6; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
            continue;
        if (tilemap[nxt_y][nxt_x] == 'x')
            continue;

        if (matched[nxt_y][nxt_x].first == -1 || match(matched[nxt_y][nxt_x]))
        {
            matched[nxt_y][nxt_x] = cur;
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t C;
    cin >> C;
    for (size_t tc = 0; tc < C; ++tc)
    {
        int seat_cnt = 0, match_cnt = 0;
        cin >> N >> M;
        for (size_t i = 0; i < N; ++i)
        {
            cin >> tilemap[i];
            for (size_t j = 0; j < M; ++j)
            {
                if (tilemap[i][j] == '.')
                    ++seat_cnt;
            }
        }

        fill_n(&matched[0][0], 80 * 80, P(-1, -1));
        for (int y = N - 1; y >= 0; --y)
        {
            for (int x = 0; x < M; x += 2)
            {
                if (tilemap[y][x] == 'x')
                    continue;

                memset(visited, false, sizeof(visited));
                match_cnt += match({y, x});
            }
        }

        cout << seat_cnt - match_cnt << '\n';
    }
}