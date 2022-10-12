#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

void solve()
{
    int N;
    cin >> N;

    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> a[i] >> b[i];

    vector<vector<int>> cache(2, vector<int>(100 * N + 1, INF));

    cache[0][0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        int cur = i % 2;
        int pre = (i - 1) % 2;

        for (int j = 0; j <= N * 100; ++j)
        {
            cache[cur][j] = INF;

            if (j - a[i] >= 0)
                cache[cur][j] = min(cache[cur][j], cache[pre][j - a[i]]);

            cache[cur][j] = min(cache[cur][j], cache[pre][j] + b[i]);
        }
    }

    int ans = INF;
    for (int t = 0; t <= N * 100; ++t)
        ans = min(ans, max(t, cache[N % 2][t]));

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
        solve();
}