#include <iostream>
using namespace std;

int N;
char board[501][501];

int get_cnt(int y, int x)
{
    static int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int ret = 0;
    for (int i = 0; i < 8; ++i)
    {
        int _y = y + dy[i], _x = x + dx[i], cnt = 0;
        while (_y >= 0 && _y < N && _x >= 0 && _x < N)
        {
            if (board[_y][_x] == '.')
                break;
            if (board[_y][_x] == 'B')
            {
                ret += cnt;
                break;
            }

            ++cnt; // board[_y][_x] == 'W'
            _y += dy[i];
            _x += dx[i];
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    int max_cnt = 0, y, x;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == '.')
            {
                int cnt = get_cnt(i, j);
                if (cnt > max_cnt)
                {
                    max_cnt = cnt;
                    y = i;
                    x = j;
                }
            }
        }
    }

    if (max_cnt == 0)
    {
        cout << "PASS" << '\n';
    }
    else
    {
        cout << x << " " << y << '\n';
        cout << max_cnt << '\n';
    }
}