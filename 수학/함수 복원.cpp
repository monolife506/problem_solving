#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

bool f[501][501], in[501], out[501];
int is_cycle[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
            cin >> f[i][j];
    }

    ll ans = 1;
    for (int i = 1; i <= N; ++i)
    {
        if (is_cycle[i] != 0)
            continue;

        int cycle_sz = 1;
        for (int j = 1; j <= N; ++j)
        {
            if (!f[i][j])
                continue;

            if (i != j && f[j][i])
            {
                is_cycle[i] = is_cycle[j] = i;
                ++cycle_sz;
            }
        }

        if (is_cycle[i] != 0)
        {
            for (int num = 2; num < cycle_sz; ++num)
                ans = (ans * num) % MOD;

            memset(in, false, sizeof(in));
            for (int j = 1; j <= N; ++j)
            {
                if (is_cycle[j] == i || !f[j][i])
                    continue;

                bool in_flag = true;
                for (int k = 1; k <= N; ++k)
                {
                    if (!f[j][k] || is_cycle[k] == i)
                        continue;

                    if (!in[k])
                        in[k] = true;
                    else
                        in_flag = false;
                }

                if (in_flag)
                    ans = (ans * cycle_sz) % MOD;
            }

            memset(out, false, sizeof(out));
            for (int j = 1; j <= N; ++j)
            {
                if (!f[i][j])
                    continue;
                if (!f[j][i])
                    out[j] = true;
            }
            for (int j = 1; j <= N; ++j)
            {
                if (is_cycle[j] == i || !out[j])
                    continue;

                bool out_flag = true;
                for (int k = 1; k <= N; ++k)
                {
                    if (!f[j][k])
                        continue;

                    if (out[k])
                        out[k] = false;
                    else
                        out_flag = false;
                }

                if (out_flag)
                    ans = (ans * cycle_sz) % MOD;
            }
        }
    }

    cout << ans << '\n';
}

/*

5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
0 0 0 1 0
0 0 0 1 1

2 * 3 = 6

5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
0 0 0 1 0
0 0 0 0 1

3 * 3 * 2 = 18

4
1 1 1 1
1 0 1 1
1 0 0 1
1 0 0 0

1

4
1 0 0 1
0 1 0 1
0 0 1 1
0 0 0 1

1

7
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
0 0 0 1 1 1 1
0 0 0 0 1 1 1
0 0 0 0 1 1 1
0 0 0 0 1 1 1

2 * 3 * 2 * 3 = 36

3
1 0 0
0 1 0
0 0 1

1

6

1 0 0 1 1 1
0 1 0 1 1 1
0 0 1 1 1 1
0 0 0 1 1 1
0 0 0 1 1 1
0 0 0 1 1 1

2 * 3 * 3 * 3 = 54

*/