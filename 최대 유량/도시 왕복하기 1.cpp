#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 987654321;

vector<int> network[401];
int c[401][401], f[401][401], pre[401];

int MaximumFlow(int source, int sink)
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

        int flow = INF;
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

    int N, P;
    cin >> N >> P;
    for (size_t i = 0; i < P; i++)
    {
        int u, v;
        cin >> u >> v;
        network[u].push_back(v);
        network[v].push_back(u);
        c[u][v]++;
    }

    cout << MaximumFlow(1, 2) << '\n';
}