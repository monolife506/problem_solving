// 1987번: 알파벳

#include <iostream>
using namespace std;

int R, C, maxCnt = 0;
bool flag[26];
char map[20][20];

void dfs(int r, int c, int cnt)
{
    static int dr[4] = {1, -1, 0, 0};
    static int dc[4] = {0, 0, 1, -1};

    if (cnt > maxCnt)
        maxCnt = cnt;

    flag[map[r][c] - 'A'] = true;
    for (size_t i = 0; i < 4; i++)
    {
        int nextR = r + dr[i];
        int nextC = c + dc[i];
        if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C)
            continue;
        if (!flag[map[nextR][nextC] - 'A'])
            dfs(nextR, nextC, cnt + 1);
    }
    flag[map[r][c] - 'A'] = false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (size_t i = 0; i < R; i++)
        for (size_t j = 0; j < C; j++)
            cin >> map[i][j];

    dfs(0, 0, 1);
    cout << maxCnt;
}