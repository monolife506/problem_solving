#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;

vector<int> graph[102];
int N, source, sink, total_sum, c[102][102], f[102][102];

int maximum_flow(int max_num)
{
    static int pre[102];

    for (size_t i = 1; i <= N; ++i)
    {
        for (size_t j = 1; j <= N; ++j)
            c[i][N + j] = max_num;
    }

    int ret = 0;
    memset(f, 0, sizeof(f));

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

        ret += flow;
    }

    return ret;
}

int parametric_search()
{
    int l = 0;
    int r = total_sum;
    int mid, ans;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (maximum_flow(mid) == total_sum)
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    source = 0;
    sink = N * 2 + 1;
    for (size_t i = 1; i <= N; ++i)
    {
        int row_sum;
        cin >> row_sum;
        c[source][i] = row_sum;
        total_sum += row_sum;

        graph[source].push_back(i);
        graph[i].push_back(source);
        for (size_t j = 1; j <= N; ++j)
        {
            graph[i].push_back(N + j);
            graph[N + j].push_back(i);
        }
    }
    for (size_t i = 1; i <= N; ++i)
    {
        int col_sum;
        cin >> col_sum;
        c[N + i][N * 2 + 1] = col_sum;

        graph[N + i].push_back(sink);
        graph[sink].push_back(N + i);
    }

    int ans = parametric_search();
    cout << ans << '\n';

    maximum_flow(ans);
    for (size_t i = 1; i <= N; ++i)
    {
        for (size_t j = 1; j <= N; ++j)
            cout << f[i][N + j] << " ";
        cout << '\n';
    }
}