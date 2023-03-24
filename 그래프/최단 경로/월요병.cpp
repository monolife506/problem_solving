#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 9e14;

int N, M, tilemap[302][302];

ll dijkstra(P start = {N + 1, 0}, P dest = {0, M + 1})
{
    const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

    priority_queue<pair<ll, P>, vector<pair<ll, P>>, greater<pair<ll, P>>> pq;
    vector<vector<ll>> dist(N + 2, vector<ll>(M + 2, INF));
    pq.push({dist[start.first][start.second] = 0, start});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        if (d > dist[y][x])
            continue;

        for (int i = 0; i < 8; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y > N + 1 || nxt_x < 0 || nxt_x > M + 1)
                continue;
            if (tilemap[nxt_y][nxt_x] == -1)
                continue;

            int w = (tilemap[nxt_y][nxt_x] != -2) ? tilemap[nxt_y][nxt_x] : 0;
            if (dist[nxt_y][nxt_x] > dist[y][x] + w)
            {
                dist[nxt_y][nxt_x] = dist[y][x] + w;
                pq.push({dist[nxt_y][nxt_x], {nxt_y, nxt_x}});
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

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
            cin >> tilemap[i][j];
    }

    for (int i = 0; i <= N + 1; ++i)
        tilemap[i][0] = tilemap[i][M + 1] = -2;
    for (int j = 0; j <= M + 1; ++j)
        tilemap[0][j] = tilemap[N + 1][j] = -2;

    tilemap[0][0] = tilemap[1][0] = tilemap[0][1] = -1;
    tilemap[N + 1][M] = tilemap[N][M + 1] = tilemap[N + 1][M + 1] = -1;

    ll ans = dijkstra();
    cout << (ans != INF ? ans : -1) << '\n';
}