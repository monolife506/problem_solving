#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
string tilemap[50];
bool ans, visited[50][50];

int dfs(int y, int x, int d)
{
    static const int dy[] = {-1, 0, 1, 0};
    static const int dx[] = {0, 1, 0, -1};

    int ret = 1;

    visited[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= n || nxt_x < 0 || nxt_x >= m)
            continue;
        if (tilemap[nxt_y][nxt_x] == '.' || visited[nxt_y][nxt_x])
            continue;

        if (d == i)
            ans = false;

        ret += dfs(nxt_y, nxt_x, i);
    }

    return ret;
}

int dfs2(int y, int x)
{
    static const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    static const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int ret = 1;

    visited[y][x] = true;
    for (int i = 0; i < 8; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= n || nxt_x < 0 || nxt_x >= m)
            continue;
        if (tilemap[nxt_y][nxt_x] == '.' || visited[nxt_y][nxt_x])
            continue;

        ret += dfs2(nxt_y, nxt_x);
    }

    return ret;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> tilemap[i];

    ans = true;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (tilemap[i][j] == '*' && !visited[i][j])
            {
                if (dfs(i, j, -1) != 3)
                    ans = false;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (tilemap[i][j] == '*' && !visited[i][j])
            {
                if (dfs2(i, j) != 3)
                    ans = false;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}