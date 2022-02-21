#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
int N, M, cost[18][18], cache[18][1 << 18], pre[18][1 << 18];

int min_cost(int cur, int mask)
{
    if (cache[cur][mask] != -1)
        return cache[cur][mask];

    if (mask == 0)
    {
        if (cost[0][cur] != -1)
            return cost[0][cur];
        else
            return INF;
    }

    cache[cur][mask] = INF;
    for (int i = 0; i < N; ++i)
    {
        if (cost[i][cur] == -1 || !(mask & (1 << i)))
            continue;

        int pre_cost = max(min_cost(i, (mask & ~(1 << i))), cost[i][cur]);
        if (cache[cur][mask] > pre_cost)
        {
            cache[cur][mask] = pre_cost;
            pre[cur][mask] = i;
        }
    }

    return cache[cur][mask];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(cost, -1, sizeof(cost));
    memset(cache, -1, sizeof(cache));
    memset(pre, -1, sizeof(pre));

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        cost[u - 1][v - 1] = c;
    }

    int ans = min_cost(0, (1 << N) - 2);
    cout << (ans != INF ? ans : -1) << '\n';
    if (ans != INF)
    {
        int cur = 0, mask = (1 << N) - 2;

        vector<int> v;
        while (pre[cur][mask] != -1)
        {
            cur = pre[cur][mask];
            mask = (mask & ~(1 << cur));
            v.push_back(cur);
        }

        cout << 1 << " ";
        for (int i = v.size() - 1; i >= 0; --i)
            cout << v[i] + 1 << " ";

        cout << '\n';
    }
}