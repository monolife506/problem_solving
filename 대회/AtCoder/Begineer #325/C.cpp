#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int h, w;
char tilemap[1001][1001];
bool visited[1000][1000];

void dfs(int y, int x)
{
    static const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
    static const int dy[] = {-1, 0, 1, 0, 1, -1, 1, -1};

    visited[y][x] = true;
    for (int i = 0; i < 8; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= h || nxt_x < 0 || nxt_x >= w)
            continue;
        if (tilemap[nxt_y][nxt_x] == '.' || visited[nxt_y][nxt_x])
            continue;

        dfs(nxt_y, nxt_x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        cin >> tilemap[i];

    int ans = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (tilemap[i][j] == '#' && !visited[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << '\n';
}