#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int s[20][20];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> s[i][j];
    }

    int ans = 987654321;
    for (int i = 1; i < (1 << n) - 1; ++i)
    {
        int score[2] = {};
        for (int j = 0; j + 1 < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                bool flag[2] = {};
                flag[0] = (i & (1 << j)) != 0;
                flag[1] = (i & (1 << k)) != 0;
                if (flag[0] == flag[1])
                {
                    score[flag[0]] += s[j][k];
                    score[flag[0]] += s[k][j];
                }
            }
        }

        ans = min(ans, abs(score[0] - score[1]));
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}

/*

o

xx*xx
 *
* * *

*/