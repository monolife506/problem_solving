#include <cstring>
#include <iostream>
using namespace std;

const int INF = 987654321;
int n, d[20][20], cache[21][1 << 20];

int dp(int cur, int mask)
{
    if (cache[cur][mask] != -1)
        return cache[cur][mask];
    if (cur == 0)
        return 0;

    cache[cur][mask] = INF;
    for (int i = 0; i < n; ++i)
    {
        if ((mask & (1 << i)) == 0)
            continue;
        cache[cur][mask] = min(cache[cur][mask], dp(cur - 1, mask & ~(1 << i)) + d[cur - 1][i]);
    }

    return cache[cur][mask];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> d[i][j];
    }

    cout << dp(n, (1 << n) - 1) << '\n';
}