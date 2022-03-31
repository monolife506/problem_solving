#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int grade[6][6] = {{10, 8, 7, 5, 0, 1},
                         {8, 6, 4, 3, 0, 1},
                         {7, 4, 3, 2, 0, 1},
                         {5, 3, 2, 2, 0, 1},
                         {0, 0, 0, 0, 0, 0},
                         {1, 1, 1, 1, 0, 0}};

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<int> graph[2502];
int c[2502][2502], f[2502][2502], d[2502][2502];

pair<int, int> mcmf(int source, int sink)
{
    static int dist[2502], pre[2502];
    static bool in_queue[2502];

    int max_flow = 0;
    int min_cost = 0;
    while (true)
    {
        queue<int> q;
        fill_n(&dist[0], 2502, INF);
        memset(pre, -1, sizeof(pre));
        memset(in_queue, false, sizeof(in_queue));

        q.push(source);
        dist[source] = 0;
        in_queue[source] = true;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            in_queue[cur] = false;
            for (int nxt : graph[cur])
            {
                if (c[cur][nxt] - f[cur][nxt] > 0 && dist[nxt] > dist[cur] + d[cur][nxt])
                {
                    dist[nxt] = dist[cur] + d[cur][nxt];
                    pre[nxt] = cur;
                    if (!in_queue[nxt])
                    {
                        q.push(nxt);
                        in_queue[nxt] = true;
                    }
                }
            }
        }

        if (pre[sink] == -1)
            break;

        int flow = INF;
        for (int i = sink; i != source; i = pre[i])
            flow = min(flow, c[pre[i]][i] - f[pre[i]][i]);
        for (int i = sink; i != source; i = pre[i])
        {
            f[pre[i]][i] += flow;
            f[i][pre[i]] -= flow;
            min_cost += d[pre[i]][i];
        }

        max_flow += flow;
    }

    return {max_flow, min_cost};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N >> M;

    char tofu[51][51];
    for (size_t i = 0; i < N; ++i)
        cin >> tofu[i];

    for (size_t y = 0; y < N; ++y)
    {
        for (size_t x = 0; x < M; ++x)
        {
            int cur = y * M + x + 1;
            if (y % 2 == x % 2)
            {
                graph[0].push_back(cur);
                graph[cur].push_back(0);
                c[0][cur] = 1;

                for (size_t i = 0; i < 4; ++i)
                {
                    int nxt_y = y + dy[i];
                    int nxt_x = x + dx[i];
                    if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                        continue;

                    int nxt = nxt_y * M + nxt_x + 1;
                    graph[cur].push_back(nxt);
                    graph[nxt].push_back(cur);
                    c[cur][nxt] = 1;
                    d[cur][nxt] = -grade[tofu[y][x] - 'A'][tofu[nxt_y][nxt_x] - 'A'];
                    d[nxt][cur] = grade[tofu[y][x] - 'A'][tofu[nxt_y][nxt_x] - 'A'];
                }
            }

            graph[cur].push_back(N * M + 1);
            graph[N * M + 1].push_back(cur);
            c[cur][N * M + 1] = 1;
        }
    }

    pair<int, int> ans = mcmf(0, N * M + 1);
    cout << -ans.second << '\n';
}