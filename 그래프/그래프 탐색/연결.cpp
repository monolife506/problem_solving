#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 98765421;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M, dist[101][101];
P pre[101][101];

int bfs(P start, P dest, P start2 = {-1, -1}, P dest2 = {-1, -1}, bool trace = false)
{
    if (trace)
    {
        for (size_t i = 0; i <= N; i++)
        {
            for (size_t j = 0; j <= M; j++)
            {
                dist[i][j] = INF;
                pre[i][j] = {-1, -1};
            }
        }
    }

    int ret;
    queue<P> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y > N || nxt_x < 0 || nxt_x > M)
                continue;
            if (dist[nxt_y][nxt_x] == -1 || start2 == P(nxt_y, nxt_x) || dest2 == P(nxt_y, nxt_x))
                continue;

            if (dist[nxt_y][nxt_x] > dist[y][x] + 1)
            {
                q.push({nxt_y, nxt_x});
                dist[nxt_y][nxt_x] = dist[y][x] + 1;
                if (trace)
                    pre[nxt_y][nxt_x] = {y, x};
            }
        }
    }

    ret = dist[dest.first][dest.second];

    if (trace)
    {
        for (size_t i = 0; i <= N; i++)
            for (size_t j = 0; j <= M; j++)
                dist[i][j] = INF;

        P cur = dest;
        while (cur.first != -1)
        {
            dist[cur.first][cur.second] = -1;
            cur = pre[cur.first][cur.second];
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ans1, ans2;
    cin >> N >> M;

    P A1, A2, B1, B2;
    cin >> A1.first >> A1.second >> A2.first >> A2.second;
    cin >> B1.first >> B1.second >> B2.first >> B2.second;

    ans1 = min(INF, bfs(A1, A2, B1, B2, true) + bfs(B1, B2));
    ans2 = min(INF, bfs(B1, B2, A1, A2, true) + bfs(A1, A2));

    if (ans1 == INF && ans2 == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << min(ans1, ans2) << '\n';
}