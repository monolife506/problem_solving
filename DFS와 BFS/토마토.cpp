// 7576번: 토마토
// 옛날 jot같은 코드 2년 뒤에 수정하기

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int M, N, total = 0;
int tomato[1000][1000];
queue<P> Q;

int BFS()
{
    static int dx[4] = { 1, -1, 0, 0 };
    static int dy[4] = { 0, 0, 1, -1 };

    int cnt = 0;
    int last = 1;
    while (!Q.empty()) {
        P cur = Q.front();
        Q.pop();
        cnt++;

        for (size_t i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x < 0 || x >= N || y < 0 || y >= M)
                continue;
            if (tomato[x][y] == 0) {
                tomato[x][y] = tomato[cur.first][cur.second] + 1;
                last = tomato[x][y];
                Q.push(P(x, y));
            }
        }
    }

    if (total != cnt)
        return -1;
    return last - 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                Q.push(P(i, j));
            if (tomato[i][j] != -1)
                total++;
        }
    }

    cout << BFS() << '\n';
}