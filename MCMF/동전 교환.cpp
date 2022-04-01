#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 1002;
const int INF = 987654321;

int c[MAX_N][MAX_N], f[MAX_N][MAX_N], d[MAX_N][MAX_N], pre[MAX_N], dist[MAX_N];
bool in_queue[MAX_N];

int mcmf(vector<vector<int>> &graph, int source, int sink)
{
    memset(f, 0, sizeof(f));

    int min_cost = 0;
    while (true)
    {
        queue<int> q;
        memset(pre, -1, sizeof(pre));
        memset(in_queue, false, sizeof(in_queue));
        fill_n(&dist[0], MAX_N, INF);

        q.push(source);
        in_queue[source] = true;
        dist[source] = 0;

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
            min_cost += d[pre[i]][i];
            f[pre[i]][i] += flow;
            f[i][pre[i]] -= flow;
        }
    }

    return min_cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        size_t n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n * 2 + 2);
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));

        for (size_t i = 1; i <= n; ++i)
        {
            graph[i * 2 - 1].push_back(i * 2);
            graph[i * 2].push_back(i * 2 - 1);
            c[i * 2 - 1][i * 2] = INF;
        }
        for (size_t i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            graph[x * 2].push_back(y * 2 - 1);
            graph[y * 2 - 1].push_back(x * 2);
            graph[y * 2].push_back(x * 2 - 1);
            graph[x * 2 - 1].push_back(y * 2);
            c[x * 2][y * 2 - 1] = c[y * 2][x * 2 - 1] = INF;
            d[x * 2][y * 2 - 1] = d[y * 2][x * 2 - 1] = 1;
            d[y * 2 - 1][x * 2] = d[x * 2 - 1][y * 2] = -1;
        }
        for (size_t i = 1; i <= n; ++i)
        {
            int node_color;
            cin >> node_color;
            if (node_color == 1)
            {
                graph[i * 2].push_back(n * 2 + 1);
                graph[n * 2 + 1].push_back(i * 2);
                c[i * 2][n * 2 + 1] = 1;
            }
        }
        for (size_t i = 1; i <= n; ++i)
        {
            int coin_color;
            cin >> coin_color;
            if (coin_color == 1)
            {
                graph[0].push_back(i * 2 - 1);
                graph[i * 2 - 1].push_back(0);
                c[0][i * 2 - 1] = 1;
            }
        }

        cout << mcmf(graph, 0, n * 2 + 1) << '\n';
    }
}