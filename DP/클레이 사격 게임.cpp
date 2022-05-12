#include <iostream>
using namespace std;

int a[16], b[16], cache[17][1 << 16];
bool can_shoot[16][1 << 16];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i] >> b[i];

    for (int mask = 0; mask < (1 << N); ++mask)
    {
        for (int i = 0; i < N; ++i)
        {
            if (mask & (1 << i))
                continue;

            can_shoot[i][mask] = true;
            for (int j = 0; j < i; ++j)
            {
                if (!(mask & (1 << j)) && a[i] >= a[j] && a[i] % a[j] == 0)
                {
                    can_shoot[i][mask] = false;
                    break;
                }
            }
        }
    }

    for (int j = 1; j <= N; ++j)
    {
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            if (__builtin_popcount(mask) != (j - 1))
                continue;
            if (j >= 2 && cache[j - 1][mask] == 0)
                continue;

            for (int i = 0; i < N; ++i)
            {
                if (can_shoot[i][mask])
                    cache[j][mask | (1 << i)] = max(cache[j][mask | (1 << i)], cache[j - 1][mask] + (b[i] * j));
            }
        }
    }

    cout << cache[N][(1 << N) - 1] << '\n';
}

/*

1 + 4 + 3 + 8 + 15

*/