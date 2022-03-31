#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;

vector<int> graph[802];
int c[802][802], d[802][802], f[802][802];

P mcmf(int source, int sink)
{
    static int dist[802], pre[802];
    static bool in_queue[802];

    int max_flow = 0;
    int min_cost = 0;

    while (true)
    {
        queue<int> q;
        fill_n(&dist[0], 802, INF);
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
    for (size_t i = 1; i <= N; ++i)
    {
        graph[0].push_back(i);
        graph[i].push_back(0);
        c[0][i] = 1;

        size_t work_cnt;
        cin >> work_cnt;
        for (size_t j = 0; j < work_cnt; ++j)
        {
            int work, cost;
            cin >> work >> cost;
            graph[i].push_back(N + work);
            graph[N + work].push_back(i);
            c[i][N + work] = 1;
            d[i][N + work] = cost;
            d[N + work][i] = -cost;
        }
    }
    for (size_t i = 1; i <= M; ++i)
    {
        graph[N + i].push_back(N + M + 1);
        graph[N + M + 1].push_back(N + i);
        c[N + i][N + M + 1] = 1;
    }

    P ans = mcmf(0, N + M + 1);
    cout << ans.first << '\n'
         << ans.second << '\n';
}