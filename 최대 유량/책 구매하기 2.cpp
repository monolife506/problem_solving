#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;

vector<int> graph[202];
int c[202][202], f[202][202];

int maximum_flow(int source, int sink)
{
    static int pre[202];

    int max_flow = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        memset(pre, -1, sizeof(pre));

        while (!q.empty() && pre[sink] == -1)
        {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur])
            {
                if (c[cur][nxt] - f[cur][nxt] > 0 && pre[nxt] == -1)
                {
                    q.push(nxt);
                    pre[nxt] = cur;
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
        }

        max_flow += flow;
    }

    return max_flow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N >> M;

    int source = 0;
    int sink = N + M + 1;
    for (size_t i = M + 1; i <= M + N; ++i)
    {
        graph[i].push_back(sink);
        graph[sink].push_back(i);
        cin >> c[i][sink];
    }
    for (size_t i = 1; i <= M; ++i)
    {
        graph[source].push_back(i);
        graph[i].push_back(source);
        cin >> c[source][i];
    }
    for (size_t i = 1; i <= M; ++i)
    {
        for (size_t j = M + 1; j <= M + N; ++j)
        {
            graph[i].push_back(j);
            graph[j].push_back(i);
            cin >> c[i][j];
        }
    }

    cout << maximum_flow(source, sink) << '\n';
}