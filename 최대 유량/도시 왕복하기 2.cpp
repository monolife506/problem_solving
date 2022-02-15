#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> network[802];
int c[802][802], f[802][802], pre[802];

int maximum_flow(int source, int sink)
{
    int total_flow = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        memset(pre, -1, sizeof(pre));

        while (!q.empty() && pre[sink] == -1)
        {
            int cur = q.front();
            q.pop();
            for (int nxt : network[cur])
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

        int flow = INT32_MAX;
        for (int cur = sink; cur != source; cur = pre[cur])
            flow = min(flow, c[pre[cur]][cur] - f[pre[cur]][cur]);
        for (int cur = sink; cur != source; cur = pre[cur])
        {
            f[pre[cur]][cur] += flow;
            f[cur][pre[cur]] -= flow;
        }

        total_flow += flow;
    }

    return total_flow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, P;
    cin >> N >> P;
    for (size_t i = 3; i <= N; i++)
    {
        network[i].push_back(i + 400);
        network[i + 400].push_back(i);
        c[i][i + 400] = 1;
    }
    for (size_t i = 0; i < P; i++)
    {
        int u, v;
        cin >> u >> v;

        if (u == 1 || u == 2)
        {
            network[u].push_back(v);
            network[v].push_back(u);
            network[v + 400].push_back(u);
            network[u].push_back(v + 400);
            c[u][v]++;
            c[v + 400][u]++;
        }
        else if (v == 1 || v == 2)
        {
            network[u + 400].push_back(v);
            network[v].push_back(u + 400);
            network[v].push_back(u);
            network[u].push_back(v);
            c[u + 400][v]++;
            c[v][u]++;
        }
        else
        {
            network[u + 400].push_back(v);
            network[v].push_back(u + 400);
            network[v + 400].push_back(u);
            network[u].push_back(v + 400);
            c[u + 400][v]++;
            c[v + 400][u]++;
        }
    }

    cout << maximum_flow(1, 2) << '\n';
}