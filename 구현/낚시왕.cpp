#include <iostream>
#include <queue>
using namespace std;

struct Shark
{
    int s, d, z;
    Shark(int _s, int _d, int _z)
    {
        s = _s;
        d = _d;
        z = _z;
    }
    bool operator<(const Shark &right) const
    {
        return z > right.z;
    }
};

int R, C, M, ans;
priority_queue<Shark> board[101][101];

void fishing(int c)
{
    for (size_t i = 1; i <= R; i++)
    {
        if (!board[i][c].empty())
        {
            ans += board[i][c].top().z;
            board[i][c].pop();
            break;
        }
    }
}

void shark_move()
{
    priority_queue<Shark> board_new[101][101];

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (board[i][j].empty())
                continue;

            Shark cur = board[i][j].top();
            board[i][j].pop();

            int dir, next, tmp;
            if (cur.d == 1) // 위
            {
                if (i - cur.s >= 1)
                {
                    board_new[i - cur.s][j].push(cur);
                    continue;
                }

                tmp = cur.s - (i - 1);
                dir = (((tmp - 1) / (R - 1)) % 2 == 1) ? 1 : 2;
                tmp = (tmp - 1) % (R - 1) + 1;
                next = (dir == 1) ? (R - tmp) : (tmp + 1);
                board_new[next][j].push(Shark(cur.s, dir, cur.z));
            }
            else if (cur.d == 2) // 아래
            {
                if (i + cur.s <= R)
                {
                    board_new[i + cur.s][j].push(cur);
                    continue;
                }

                tmp = cur.s - (R - i);
                dir = (((tmp - 1) / (R - 1)) % 2 == 1) ? 2 : 1;
                tmp = (tmp - 1) % (R - 1) + 1;
                next = (dir == 1) ? (R - tmp) : (tmp + 1);
                board_new[next][j].push(Shark(cur.s, dir, cur.z));
            }
            else if (cur.d == 3) // 오른쪽
            {
                if (j + cur.s <= C)
                {
                    board_new[i][j + cur.s].push(cur);
                    continue;
                }

                tmp = cur.s - (C - j);
                dir = (((tmp - 1) / (C - 1)) % 2 == 1) ? 3 : 4;
                tmp = (tmp - 1) % (C - 1) + 1;
                next = (dir == 3) ? (tmp + 1) : (C - tmp);
                board_new[i][next].push(Shark(cur.s, dir, cur.z));
            }
            else // 왼쪽
            {
                if (j - cur.s >= 1)
                {
                    board_new[i][j - cur.s].push(cur);
                    continue;
                }

                tmp = cur.s - (j - 1);
                dir = (((tmp - 1) / (C - 1)) % 2 == 1) ? 4 : 3;
                tmp = (tmp - 1) % (C - 1) + 1;
                next = (dir == 3) ? (tmp + 1) : (C - tmp);
                board_new[i][next].push(Shark(cur.s, dir, cur.z));
            }
        }
    }

    for (size_t i = 1; i <= R; i++)
    {
        for (size_t j = 1; j <= C; j++)
        {
            board[i][j] = board_new[i][j];
            while (board[i][j].size() > 1)
                board[i][j].pop();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> M;
    for (size_t i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c].push(Shark(s, d, z));
    }

    for (size_t i = 1; i <= C; i++)
    {
        fishing(i);
        shark_move();
    }

    cout << ans << '\n';
}

//  3  2  1 XX
// XX  4  5  6
//  9  8  7 XX

// 2 1 0 X
// X 3 4 5
// 8 7 6 X