#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;

vector<int> graph[202];
int c[202][202], f[202][202], d[202][202];

pair<int, int> mcmf(int source, int sink)
{
    static int dist[202], pre[202];
    static bool in_queue[202];

    int max_flow = 0;
    int min_cost = 0;

    while (true)
    {
        queue<int> q;
        fill_n(&dist[0], 202, INF);
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
            min_cost += flow * d[pre[i]][i];
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
    for (size_t i = M + 1; i <= N + M; ++i)
    {
        graph[i].push_back(N + M + 1);
        graph[N + M + 1].push_back(i);
        cin >> c[i][N + M + 1];
    }
    for (size_t i = 1; i <= M; ++i)
    {
        graph[0].push_back(i);
        graph[i].push_back(0);
        cin >> c[0][i];
    }

    for (size_t i = 1; i <= M; ++i)
    {
        for (size_t j = M + 1; j <= N + M; ++j)
        {
            graph[i].push_back(j);
            graph[j].push_back(i);
            cin >> c[i][j];
        }
    }
    for (size_t i = 1; i <= M; ++i)
    {
        for (size_t j = M + 1; j <= N + M; ++j)
        {
            cin >> d[i][j];
            d[j][i] = -d[i][j];
        }
    }

    pair<int, int> ans = mcmf(0, M + N + 1);
    cout << ans.first << '\n'
         << ans.second << '\n';
}