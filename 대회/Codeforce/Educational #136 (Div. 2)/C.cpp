#include <iostream>
using namespace std;

const int MOD = 998244353;

int c[61][61];

void solve()
{
    int n;
    cin >> n;

    int total = c[n][n / 2];
    int alex = c[n - 1][n / 2];
    for (int i = 3; i <= n / 2; i += 2)
    {
        alex = (alex + c[n - 2 * (i - 1)][n / 2 - i]) % MOD;
        alex = (alex + c[n - 2 * (i - 1) - 1][n / 2 - i]) % MOD;
    }

    cout << alex << " " << ((total - alex + MOD) % MOD + (MOD - 1)) % MOD << " " << 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 60; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}

/*

Alex -> Boris -> ...

10 ? ? ? ?

9 8 7 ? ? 10 - 4, 2
9 8 6 ? ? 10 - 5, 2

9 8 5 4 3
9 8 5 4 2

8 ? ? ?
7 6 5 ? 8 - 4, 1
7 6 4 ? 8 - 5, 1

*/