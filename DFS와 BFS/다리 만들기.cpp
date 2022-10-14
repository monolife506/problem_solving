#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int N, tilemap[100][100];

void dfs(int y, int x, int num)
{
    tilemap[y][x] = num;
    for (int i = 0; i < 4; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= N)
            continue;
        if (tilemap[nxt_y][nxt_x] != -1)
            continue;

        dfs(nxt_y, nxt_x, num);
    }
}

int bfs(int island_num)
{
    queue<pii> q;
    vector<vector<int>> dist(N, vector<int>(N, -1));

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (tilemap[y][x] != 0)
                continue;

            bool flag = false;
            for (int i = 0; i < 4; ++i)
            {
                int nxt_y = y + dy[i];
                int nxt_x = x + dx[i];
                if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= N)
                    continue;
                if (tilemap[nxt_y][nxt_x] != island_num)
                    continue;

                flag = true;
                break;
            }

            if (flag)
            {
                q.push({y, x});
                dist[y][x] = 0;
            }
        }
    }

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= N)
                continue;
            if (dist[nxt_y][nxt_x] != -1)
                continue;

            if (tilemap[nxt_y][nxt_x] == 0)
            {
                q.push({nxt_y, nxt_x});
                dist[nxt_y][nxt_x] = dist[y][x] + 1;
            }
            else if (tilemap[nxt_y][nxt_x] != island_num)
            {
                return dist[y][x] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> tilemap[i][j];
            if (tilemap[i][j] == 1)
                tilemap[i][j] = -1;
        }
    }

    int island_cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (tilemap[i][j] == -1)
                dfs(i, j, ++island_cnt);
        }
    }

    int ans = INT32_MAX;
    for (int i = 1; i <= island_cnt; ++i)
        ans = min(ans, bfs(i));

    cout << ans << '\n';
}