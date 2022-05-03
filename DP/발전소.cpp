#include <iostream>
using namespace std;

const int INF = 987654321;

size_t N, P;
int cost[16][16], cache[1 << 16];

int dp(int mask)
{
    if (cache[mask] != -1)
        return cache[mask];

    cache[mask] = INF;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
                continue;
            if ((mask & (1 << i)) && (mask & (1 << j)))
                cache[mask] = min(cache[mask], dp(mask & ~(1 << j)) + cost[i][j]);
        }
    }

    return cache[mask];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; ++j)
            cin >> cost[i][j];
    }

    char str[17];
    cin >> str;

    int start = 0;
    for (size_t i = 0; i < N; ++i)
    {
        if (str[i] == 'Y')
            start |= (1 << i);
    }

    cin >> P;
    if (start == 0)
    {
        cout << (P == 0 ? 0 : -1) << '\n';
    }
    else
    {
        for (int mask = 0; mask < (1 << N); ++mask)
            cache[mask] = (mask & start) ? -1 : INF;

        cache[start] = 0;
        dp((1 << N) - 1);

        int ans = INF;
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            if ((mask & start) && __builtin_popcount(mask) >= P)
                ans = min(ans, cache[mask]);
        }

        cout << (ans != INF ? ans : -1) << '\n';
    }
}