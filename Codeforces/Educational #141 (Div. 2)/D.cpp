#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;

int a[301], cache[301][180001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    cache[2][a[3] - a[2] + 90000] = 1;
    cache[2][a[3] + a[2] + 90000] = 1;
    for (int i = 2; i <= n - 2; ++i)
    {
        for (int j = -90000; j <= 90000; ++j)
        {
            int pre = j + 90000;
            if (j == 0)
            {
                cache[i + 1][a[i + 2] + 90000] += cache[i][pre];
                cache[i + 1][a[i + 2] + 90000] %= MOD;
            }
            else
            {
                cache[i + 1][a[i + 2] + j + 90000] += cache[i][pre];
                cache[i + 1][a[i + 2] + j + 90000] %= MOD;
                cache[i + 1][a[i + 2] - j + 90000] += cache[i][pre];
                cache[i + 1][a[i + 2] - j + 90000] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 180000; ++i)
    {
        ans += cache[n - 1][i];
        ans %= MOD;
    }

    cout << ans << '\n';
}

/*

1 1 1 1
cache[1][1][2] = 1
cache[1][1][0] = 1

cache[2][-1][3] = 1
cache[2][3][-1] = 1

cache[1][1][0]


300 300 300 300 300 300
0 300 600 300 300 300
0 -300 600 900 300 300
0 -300 -300 900 1200 300


*/