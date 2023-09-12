#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
ll D[16][16], cache[1 << 16];

ll dp(int cur)
{
    if (cur == 0)
        return 0;
    if (cache[cur] != -1)
        return cache[cur];

    cache[cur] = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
                continue;
            if (!(cur & (1 << i)) || !(cur & (1 << j)))
                continue;

            int nxt = cur;
            nxt ^= (1 << i);
            nxt ^= (1 << j);

            cache[cur] = max(cache[cur], dp(nxt) + D[i][j]);
        }
    }

    return cache[cur];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            cin >> D[i][j];
            D[j][i] = D[i][j];
        }
    }

    if (N % 2 == 0)
    {
        cout << dp((1 << N) - 1) << '\n';
    }
    else
    {
        ll ans = 0;
        for (int i = 0; i < N; ++i)
            ans = max(ans, dp(((1 << N) - 1) ^ (1 << i)));

        cout << ans << '\n';
    }
}

/*



*/