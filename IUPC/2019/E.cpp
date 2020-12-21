#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000];
bool visited[1000][1000];
char buffer[1001];

struct Qitem
{
    int X;
    int Y;
    int L;
    int R;
    Qitem(int _X, int _Y, int _L, int _R) : X(_X), Y(_Y), L(_L), R(_R) {}
};

int bfs(int N, int M, int lCnt, int rCnt, int startX, int startY)
{
    static int dx[4] = {1, -1, 0, 0};
    static int dy[4] = {0, 0, 1, -1};

    int ans = 1;
    queue<Qitem> Q;
    Q.push(Qitem(startX, startY, lCnt, rCnt));
    visited[startX][startY] = true;

    while (!Q.empty())
    {
        Qitem cur = Q.front();
        Q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int X = cur.X;
            int Y = cur.Y + dy[i];

            // 상하 탐색
            if (i == 0 || i == 1)
            {
                while (X >= 0 && X < N)
                {
                    X += dx[i];
                    if (X < 0 || X >= N || arr[X][Y] == 1)
                        break;
                    if (!visited[X][Y])
                    {
                        ans++;
                        visited[X][Y] = true;
                        Q.push(Qitem(X, Y, cur.L, cur.R));
                    }
                }
            }
            else // 좌우 탐색
            {
                if (Y < 0 || Y >= M || arr[X][Y] == 1)
                    continue;
                if (!visited[X][Y])
                {
                    if (i == 2 && cur.R > 0)
                    {
                        ans++;
                        visited[X][Y] = true;
                        Q.push(Qitem(X, Y, cur.L, cur.R - 1));
                    }
                    else if (i == 3 && cur.L > 0)
                    {
                        ans++;
                        visited[X][Y] = true;
                        Q.push(Qitem(X, Y, cur.L - 1, cur.R));
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, L, R, startX, startY;
    cin >> N >> M >> L >> R;
    for (size_t i = 0; i < N; i++)
    {
        cin >> buffer;
        for (size_t j = 0; j < M; j++)
        {
            arr[i][j] = buffer[j] - '0';
            if (arr[i][j] == 2)
            {
                startX = i;
                startY = j;
            }
        }
    }

    cout << bfs(N, M, L, R, startX, startY);
}