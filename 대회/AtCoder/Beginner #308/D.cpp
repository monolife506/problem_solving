#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const char chr[] = {'s', 'n', 'u', 'k', 'e'};

int H, W;
char grid[501][501];
bool visited[501][501];

void dfs(int c, int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nxt_c = (c + 1) % 5;
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= H || nxt_x < 0 || nxt_x >= W)
            continue;
        if (grid[nxt_y][nxt_x] != chr[nxt_c])
            continue;
        if (visited[nxt_y][nxt_x])
            continue;

        dfs(nxt_c, nxt_y, nxt_x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W;
    for (int i = 0; i < H; ++i)
        cin >> grid[i];

    if (grid[0][0] != 's')
    {
        cout << "No" << '\n';
    }
    else
    {
        dfs(0, 0, 0);
        cout << (visited[H - 1][W - 1] ? "Yes" : "No") << '\n';
    }
}