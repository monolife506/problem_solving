#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N, M, T, a[5001], x[5001], y[5001], c[5001], cache[2][101][5001];
vector<int> adj[5001];

int dp(int d)
{
    memset(cache, -1, sizeof(cache));
    cache[0][0][1] = 0;

    int ret = 0;
    for (int t = 1; t <= T; ++t)
    {
        for (int i = 1; i <= N; ++i)
        {
            if (cache[0][t - 1][i] != -1 && a[i] + x[i] * (t - 1) <= (ll)y[i] * d)
            {
                cache[1][t][i] = max(cache[1][t][i], cache[0][t - 1][i] + c[i]);
                ret = max(ret, cache[1][t][i]);
            }

            if (cache[1][t][i] == -1)
                continue;

            for (int j : adj[i])
                cache[0][t][j] = max(cache[0][t][j], cache[1][t][i]);
        }
    }

    return ret;
}

int parametric_search(int l, int r)
{
    int ret, mid, max_c = dp(r);
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (dp(mid) >= max_c)
        {
            ret = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i] >> x[i] >> y[i] >> c[i];
    }
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << parametric_search(1, 1000990000) << '\n';
}

/*

2 2 100
1000000000 10000 1 10000
1000000000 10000 1 10000
1 2
2 1

=> 1000990000

3 2 10
1 1 1 1
2 2 1 2
3 3 1 3
1 2
2 3

=> 9

3 1 10
1 1 1 1
1 1 1 1
1 1 1 1
2 3

=> 1

독해를 열심히 합시다.

*/