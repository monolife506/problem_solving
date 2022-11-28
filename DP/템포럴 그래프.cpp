#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

ll cache[1001][10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 1001 * 10001, INF);

    int n, t, m, s, e;
    cin >> n >> t >> m >> s >> e;

    cache[0][s] = 0;
    for (int i = 1; i <= t; ++i)
    {
        for (int j = 0; j < n; ++j)
            cache[i][j] = cache[i - 1][j];

        for (int j = 0; j < m; ++j)
        {
            int u, v, w;
            cin >> u >> v >> w;

            cache[i][u] = min(cache[i][u], cache[i - 1][v] + w);
            cache[i][v] = min(cache[i][v], cache[i - 1][u] + w);
        }
    }

    ll ans = INF;
    for (int i = 1; i <= t; ++i)
        ans = min(ans, cache[i][e]);

    cout << (ans != INF ? ans : -1) << '\n';
}