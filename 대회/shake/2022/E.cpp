#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[502][502];
ll psum[502][502], min_val[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&min_val[0][0], 501 * 501, 501 * 10000);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
        for (int j = n; j > 0; --j)
            psum[i][j] += psum[i][j + 1] + a[i][j];
        for (int j = 1; j <= n; ++j)
            min_val[i][j] = min(min_val[i - 1][j], psum[i][j]);
    }

    for (int i = 0; i < q; ++i)
    {
        int sx, sy, l;
        cin >> sx >> sy >> l;

        ll ans = psum[sx][sy];
        for (int j = sy; j <= n; ++j)
            ans = min(ans, min_val[sx - l][j] + psum[sx][sy] - psum[sx][j]);

        cout << ans << '\n';
    }
}