#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, h;
    cin >> n >> h;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());
    vector<vector<vector<ll>>> cache(2, vector<vector<ll>>(3, vector<ll>(n + 1, -1)));

    cache[0][0][0] = h;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (cache[j][k][i - 1] > a[i])
                    cache[j][k][i] = max(cache[j][k][i], cache[j][k][i - 1] + (a[i] / 2));
                if (k < 2 && cache[j][k][i - 1] * 2 > a[i])
                    cache[j][k + 1][i] = max(cache[j][k + 1][i], cache[j][k][i - 1] * 2 + (a[i] / 2));
                if (k < 1 && cache[j][k][i - 1] * 4 > a[i])
                    cache[j][k + 2][i] = max(cache[j][k + 2][i], cache[j][k][i - 1] * 4 + (a[i] / 2));
                if (j < 1 && cache[j][k][i - 1] * 3 > a[i])
                    cache[j + 1][k][i] = max(cache[j + 1][k][i], cache[j][k][i - 1] * 3 + (a[i] / 2));
                if (j < 1 && k < 2 && cache[j][k][i - 1] * 6 > a[i])
                    cache[j + 1][k + 1][i] = max(cache[j + 1][k + 1][i], cache[j][k][i - 1] * 6 + (a[i] / 2));
                if (j < 1 && k < 1 && cache[j][k][i - 1] * 12 > a[i])
                    cache[j + 1][k + 2][i] = max(cache[j + 1][k + 2][i], cache[j][k][i - 1] * 12 + (a[i] / 2));
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (cache[j][k][i] != -1)
                    ans = max(ans, i);
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}