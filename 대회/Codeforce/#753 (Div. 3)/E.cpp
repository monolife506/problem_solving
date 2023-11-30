#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int xl = 0, xr = 0, yu = 0, yd = 0, x = 0, y = 0;
    int ans_x = 1, ans_y = 1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'L')
        {
            if (--x < 0 && abs(x) > xl)
                xl++;
        }
        else if (s[i] == 'R')
        {
            if (++x > 0 && abs(x) > xr)
                xr++;
        }
        else if (s[i] == 'U')
        {
            if (--y < 0 && abs(y) > yu)
                yu++;
        }
        else
        {
            if (++y > 0 && abs(y) > yd)
                yd++;
        }

        if ((xl + xr + 1) <= m && (yu + yd + 1) <= n)
        {
            ans_x = xl + 1;
            ans_y = yu + 1;
        }
    }

    cout << ans_y << " " << ans_x << '\n';
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