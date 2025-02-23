#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m;
string tilemap[1000];
int dist[2][1000][1000];

void bfs(int start_y, int start_x)
{
    queue<pair<bool, pii>> q;
    memset(dist, -1, sizeof(dist));

    if (tilemap[0][0] == '0')
    {
        q.push({true, {start_y, start_x}});
        dist[1][0][0] = 1;
    }
    else
    {
        q.push({false, {start_y, start_x}});
        dist[0][0][0] = 1;
    }

    while (!q.empty())
    {
        bool flag = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= n || nxt_x < 0 || nxt_x >= m)
                continue;

            if (flag && tilemap[nxt_y][nxt_x] == '1' && dist[0][nxt_y][nxt_x] == -1)
            {
                dist[0][nxt_y][nxt_x] = dist[1][y][x] + 1;
                q.push({false, {nxt_y, nxt_x}});
            }

            if (tilemap[nxt_y][nxt_x] == '0' && dist[flag][nxt_y][nxt_x] == -1)
            {
                dist[flag][nxt_y][nxt_x] = dist[flag][y][x] + 1;
                q.push({flag, {nxt_y, nxt_x}});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> tilemap[i];

    bfs(0, 0);

    if (dist[0][n - 1][m - 1] == -1 && dist[1][n - 1][m - 1] == -1)
        cout << -1 << endl;
    else if (dist[0][n - 1][m - 1] == -1)
        cout << dist[1][n - 1][m - 1] << endl;
    else if (dist[1][n - 1][m - 1] == -1)
        cout << dist[0][n - 1][m - 1] << endl;
    else
        cout << min(dist[0][n - 1][m - 1], dist[1][n - 1][m - 1]) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}