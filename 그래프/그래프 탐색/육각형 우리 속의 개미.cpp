#include <iostream>
using namespace std;

int N, ans, dfsn[100][100];

void dfs(int y, int x, int d, int nth)
{
    static const int dy[] = {-1, 0, 1, 0};
    static const int dx[] = {0, 1, 0, -1};

    if (nth > N + 1)
        return;

    dfsn[y][x] = nth;
    for (int i = 0; i < 4; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];

        if (i == 0 && (y + x) % 2 != 0)
            continue;
        if (i == 2 && (y + x) % 2 != 1)
            continue;
        if (i == (d + 2) % 4)
            continue;

        if (dfsn[nxt_y][nxt_x] == 0)
            dfs(nxt_y, nxt_x, i, nth + 1);
        else if (dfsn[y][x] == N + 1)
            ++ans;
    }

    dfsn[y][x] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    dfs(50, 50, -1, 1);
    cout << ans / 2 << '\n';
}