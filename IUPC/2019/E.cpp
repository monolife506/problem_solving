#include <iostream>
#include <queue>
using namespace std;

struct P
{
    int X;
    int Y;
    int L;
    int R;

    P() {}
    P(int x, int y, int l, int r) : X(x), Y(y), L(l), R(r) {}
};

int N, M, L, R;
int arr[1001][1001];

char buffer[1001];
int startX, startY;
bool visited[1001][1001];

int bfs()
{
    static int dx[4] = {1, -1, 0, 0};
    static int dy[4] = {0, 0, 1, -1};

    int ans = 0;
    queue<P> Q;
    Q.push(P(startX, startY, 0, 0));
    visited[startX][startY] = true;

    while (!Q.empty())
    {
        P cur = Q.front();
        Q.pop();

        if (cur.L <= L && cur.R <= R)
            ans++;

        for (size_t i = 0; i < 4; i++)
        {
            int nextX = cur.X + dx[i];
            int nextY = cur.Y + dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
                continue;
            if (!visited[nextX][nextY] && arr[nextX][nextY] == 0)
            {
                visited[nextX][nextY] = true;
                if (i == 2)
                    Q.push(P(nextX, nextY, cur.L, cur.R + 1));
                else if (i == 3)
                    Q.push(P(nextX, nextY, cur.L + 1, cur.R));
                else
                    Q.push(P(nextX, nextY, cur.L, cur.R));
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

    cout << bfs();
}