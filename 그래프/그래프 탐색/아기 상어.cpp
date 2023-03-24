// 16236번: 아기 상어

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

int N, sharkSize = 2, eatCnt;
int space[20][20];
P shark;

int BFS(P &start)
{
    int dist[20][20];
    int minDist = -1, targetX, targetY;
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};
    memset(dist, -1, sizeof(dist));

    queue<P> Q;
    Q.push(P(start.first, start.second));
    dist[start.first][start.second] = 0;
    while (!Q.empty())
    {
        int curY = Q.front().first;
        int curX = Q.front().second;
        Q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
                continue;
            if (dist[nextY][nextX] == -1 && space[nextY][nextX] <= sharkSize)
            {
                dist[nextY][nextX] = dist[curY][curX] + 1;
                if (minDist != -1 && dist[nextY][nextX] > minDist)
                    break;

                if (space[nextY][nextX] != 0 && space[nextY][nextX] < sharkSize)
                {
                    if (minDist == -1)
                    {
                        minDist = dist[nextY][nextX];
                        targetX = nextX;
                        targetY = nextY;
                    }
                    else if (nextY < targetY || nextY == targetY && nextX < targetX)
                    {
                        targetX = nextX;
                        targetY = nextY;
                    }
                }

                Q.push(P(nextY, nextX));
            }
        }
    }

    if (minDist != -1)
    {
        eatCnt++;
        if (eatCnt == sharkSize)
        {
            sharkSize++;
            eatCnt = 0;
        }

        space[targetY][targetX] = 0;
        shark = P(targetY, targetX);
        return dist[targetY][targetX];
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> space[i][j];
            if (space[i][j] == 9)
            {
                shark = P(i, j);
                space[i][j] = 0;
            }
        }
    }

    int ans = 0;
    int tmp = BFS(shark);
    while (tmp != -1)
    {
        ans += tmp;
        tmp = BFS(shark);
    }
    cout << ans;
}

// X O X O X
// O X X X O
// X X   X X
// X X X X X
// X X X X X