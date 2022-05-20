#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M;
int tilemap[1000][1000];

int bfs(P start, P dest, vector<vector<vector<P>>> &adj, vector<int> &dist_y, vector<int> &dist_x)
{
    queue<P> q;
    q.push(start);

    vector<vector<int>> dist(N, vector<int>(M, INF));
    dist[start.first][start.second] = dist_y[start.first] = dist_x[start.second] = 0;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (P &p : adj[y][x])
        {
            int &nxt_y = p.first;
            int &nxt_x = p.second;
            if (dist[nxt_y][nxt_x] > dist[y][x] + 1)
            {
                q.push({nxt_y, nxt_x});
                dist[nxt_y][nxt_x] = dist[y][x] + 1;
                dist_y[nxt_y] = min(dist_y[nxt_y], dist[nxt_y][nxt_x]);
                dist_x[nxt_x] = min(dist_x[nxt_x], dist[nxt_y][nxt_x]);
            }
        }
    }

    return dist[dest.first][dest.second];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int rf, cf, rh, ch;
    cin >> N >> M >> rf >> cf >> rh >> ch;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cin >> tilemap[i][j];
    }

    vector<vector<vector<P>>> adj(N, vector<vector<P>>(M));
    vector<vector<vector<P>>> adj_r(N, vector<vector<P>>(M));
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            for (int i = 0; i < 4; ++i)
            {
                int nxt_y = y + dy[i] * tilemap[y][x];
                int nxt_x = x + dx[i] * tilemap[y][x];
                if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                    continue;

                adj[y][x].push_back({nxt_y, nxt_x});
                adj_r[nxt_y][nxt_x].push_back({y, x});
            }
        }
    }

    vector<int> dist_y(N, INF), dist_x(M, INF), dist_ry(N, INF), dist_rx(M, INF);
    int ans = bfs({rf - 1, cf - 1}, {rh - 1, ch - 1}, adj, dist_y, dist_x);
    bfs({rh - 1, ch - 1}, {rf - 1, cf - 1}, adj_r, dist_ry, dist_rx);

    for (int y = 0; y < N; ++y)
        ans = min(ans, dist_y[y] + dist_ry[y] + 1);
    for (int x = 0; x < M; ++x)
        ans = min(ans, dist_x[x] + dist_rx[x] + 1);

    cout << (ans != INF ? ans : -1) << '\n';
}

/*

3 3
1 1 3 3
1 2 1
2 1 2
1 2 1

2 5
1 1 2 5
1 2 4 2 1
4 2 1 3 3

*/