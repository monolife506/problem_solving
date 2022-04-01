#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_V = 2002;
const int INF = 987654321;

int c[MAX_V][MAX_V], f[MAX_V][MAX_V], d[MAX_V][MAX_V], dist[MAX_V], pre[MAX_V];
bool in_queue[MAX_V];

int mcmf(vector<vector<int>> &graph, int source, int sink)
{
    int min_cost = 0;
    while (true)
    {
        queue<int> q;
        memset(pre, -1, sizeof(pre));
        memset(in_queue, false, sizeof(in_queue));
        fill_n(&dist[0], MAX_V, INF);

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
            f[pre[i]][i] += flow;
            f[i][pre[i]] -= flow;
            min_cost += d[pre[i]][i];
        }
    }

    return min_cost;
}

int main()
{
    size_t v, e;
    while (cin >> v >> e)
    {
        vector<vector<int>> graph(v * 2 + 2);
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(d, 0, sizeof(d));

        graph[0].push_back(2);
        graph[2].push_back(0);
        c[0][2] = 2;
        graph[v * 2 - 1].push_back(v * 2 + 1);
        graph[v * 2 + 1].push_back(v * 2 - 1);
        c[v * 2 - 1][v * 2 + 1] = 2;

        for (size_t i = 1; i <= v; ++i)
        {
            graph[i * 2 - 1].push_back(i * 2);
            graph[i * 2].push_back(i * 2 - 1);
            c[i * 2 - 1][i * 2] = 1;
        }
        for (size_t i = 0; i < e; ++i)
        {
            int a, b, cannonball_cnt;
            cin >> a >> b >> cannonball_cnt;
            graph[a * 2].push_back(b * 2 - 1);
            graph[b * 2 - 1].push_back(a * 2);
            c[a * 2][b * 2 - 1] = 1;
            d[a * 2][b * 2 - 1] = cannonball_cnt;
            d[b * 2 - 1][a * 2] = -cannonball_cnt;
        }

        cout << mcmf(graph, 0, v * 2 + 1) << '\n';
    }
}