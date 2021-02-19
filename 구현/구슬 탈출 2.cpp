#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct State {
    int cnt; // 지금까지 이동한 횟수
    int rx, ry; // 빨간 구슬의 위치
    int bx, by; // 파란 구슬의 위치

    State(int _cnt, int _rx, int _ry, int _bx, int _by)
    {
        cnt = _cnt;
        rx = _rx;
        ry = _ry;
        bx = _bx;
        by = _by;
    }
};

int N, M;
char board[10][10];

int bfs(int start[])
{
    static int dx[4] = { 1, -1, 0, 0 };
    static int dy[4] = { 0, 0, 1, -1 };

    queue<State> Q;
    Q.push(State(0, start[0], start[1], start[2], start[3]));

    while (!Q.empty()) {
        State cur = Q.front();
        Q.pop();

        if (cur.cnt >= 10)
            continue;

        for (size_t i = 0; i < 4; i++) {
            State next = State(cur.cnt + 1, cur.rx, cur.ry, cur.bx, cur.by);

            int r_cnt = 0, b_cnt = 0;
            while (board[next.rx + dx[i]][next.ry + dy[i]] != '#') {
                next.rx += dx[i];
                next.ry += dy[i];
                r_cnt++;
                if (board[next.rx][next.ry] == 'O')
                    break;
            }
            while (board[next.bx + dx[i]][next.by + dy[i]] != '#') {
                next.bx += dx[i];
                next.by += dy[i];
                b_cnt++;
                if (board[next.bx][next.by] == 'O')
                    break;
            }

            if (next.rx == next.bx && next.ry == next.by && board[next.rx][next.ry] != 'O') {
                if (r_cnt > b_cnt) {
                    next.rx -= dx[i];
                    next.ry -= dy[i];
                } else {
                    next.bx -= dx[i];
                    next.by -= dy[i];
                }
            }

            if (board[next.bx][next.by] == 'O')
                continue;
            else if (board[next.rx][next.ry] == 'O')
                return next.cnt;
            else
                Q.push(next);
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int start[4];
    cin >> N >> M;
    for (size_t i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (size_t j = 0; j < M; j++) {
            if (input[j] == 'R') {
                start[0] = i;
                start[1] = j;
                board[i][j] = '.';
                continue;
            } else if (input[j] == 'B') {
                start[2] = i;
                start[3] = j;
                board[i][j] = '.';
                continue;
            }
            board[i][j] = input[j];
        }
    }

    cout << bfs(start) << '\n';
}