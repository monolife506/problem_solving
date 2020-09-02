// 2638번: 치즈

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

int N, M, cheeseCnt;
bool map[101][101];  // 현재 치즈의 위치
bool flag[101][101]; // 현재 외부 공기에 속하는 공간들

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<P> cheeses; // 모든 치즈들의 위치

void emptyCheck()
{
    queue<P> Q;
    Q.push(P(0, 0));
    Q.push(P(N - 1, 0));
    Q.push(P(0, M - 1));
    Q.push(P(N - 1, M - 1));

    memset(flag, false, sizeof(flag));
    flag[0][0] = true;
    flag[N - 1][0] = true;
    flag[0][M - 1] = true;
    flag[N - 1][M - 1] = true;

    while (!Q.empty())
    {
        P cur = Q.front();
        Q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int X = cur.second + dx[i];
            int Y = cur.first + dy[i];
            if (X < 0 || X >= M || Y < 0 || Y >= N)
                continue;
            if (!flag[Y][X] && !map[Y][X])
            {
                flag[Y][X] = true;
                Q.push(P(Y, X));
            }
        }
    }
}

void cheeseCheck()
{
    queue<P> Q;
    Q.push(P(0, 0));
    Q.push(P(N - 1, 0));
    Q.push(P(0, M - 1));
    Q.push(P(N - 1, M - 1));

    bool visited[101][101];
    memset(visited, false, sizeof(visited));
    visited[0][0] = true;
    visited[N - 1][0] = true;
    visited[0][M - 1] = true;
    visited[N - 1][M - 1] = true;

    while (!Q.empty())
    {
        P cur = Q.front();
        Q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int X = cur.second + dx[i];
            int Y = cur.first + dy[i];
            if (X < 0 || X >= M || Y < 0 || Y >= N)
                continue;
            if (!visited[Y][X])
            {
                visited[Y][X] = true;
                if (map[Y][X])
                {
                    int adjCnt = 0;
                    for (size_t j = 0; j < 4; j++)
                    {
                        int nextX = X + dx[j];
                        int nextY = Y + dy[j];
                        if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || flag[nextY][nextX])
                            adjCnt++;
                    }
                    if (adjCnt >= 2)
                        cheeses.push(P(Y, X));
                }
                else
                    Q.push(P(Y, X));
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                cheeseCnt++;
        }
    }

    int sec = 0;
    while (cheeseCnt > 0)
    {
        emptyCheck();
        cheeseCheck();
        while (!cheeses.empty())
        {
            P cur = cheeses.front();
            cheeses.pop();

            map[cur.first][cur.second] = 0;
            cheeseCnt--;
        }

        sec++;
    }
    cout << sec;
}