#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int num[50][50], c[2502][2502], f[2502][2502], pre[2502];

int maximum_flow(vector<vector<int>> &graph, int source, int sink)
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

            for (int nxt : graph[cur])
            {
                if (c[cur][nxt] - f[cur][nxt] > 0 && pre[nxt] == -1)
                {
                    pre[nxt] = cur;
                    q.push(nxt);
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

        total_flow += flow;
    }

    return total_flow;
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
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));

        int n, m, sum = 0;
        cin >> n >> m;

        vector<vector<int>> graph(n * m + 2);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> num[i][j];
                sum += num[i][j];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int cur = i * m + j;

                if (i % 2 == j % 2)
                {
                    graph[n * m].push_back(cur);
                    graph[cur].push_back(n * m);
                    c[n * m][cur] = num[i][j];

                    for (int k = 0; k < 4; ++k)
                    {
                        int nxt_i = i + dy[k];
                        int nxt_j = j + dx[k];
                        if (nxt_i < 0 || nxt_i >= n || nxt_j < 0 || nxt_j >= m)
                            continue;

                        int nxt = nxt_i * m + nxt_j;
                        graph[cur].push_back(nxt);
                        graph[nxt].push_back(cur);
                        c[cur][nxt] = INF;
                    }
                }
                else
                {
                    graph[cur].push_back(n * m + 1);
                    graph[n * m + 1].push_back(cur);
                    c[cur][n * m + 1] = num[i][j];
                }
            }
        }

        cout << sum - maximum_flow(graph, n * m, n * m + 1) << '\n';
    }
}