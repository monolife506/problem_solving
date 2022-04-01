#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_V = 200 + 100 + 2;
const int INF = 987654321;

vector<int> graph[MAX_V];
int c[MAX_V][MAX_V], f[MAX_V][MAX_V], pre[MAX_V];

int maximum_flow(int source, int sink)
{
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

    size_t N, K, D;
    cin >> N >> K >> D;
    for (size_t i = 1; i <= D; ++i)
    {
        graph[N + i].push_back(N + D + 1);
        graph[N + D + 1].push_back(N + i);
        cin >> c[N + i][N + D + 1];
    }
    for (size_t i = 1; i <= N; ++i)
    {
        graph[0].push_back(i);
        graph[i].push_back(0);
        c[0][i] = K;

        int Z;
        cin >> Z;
        for (size_t j = 0; j < Z; ++j)
        {
            int d;
            cin >> d;
            graph[i].push_back(N + d);
            graph[N + d].push_back(i);
            c[i][N + d] = 1;
        }
    }

    cout << maximum_flow(0, N + D + 1) << '\n';
}