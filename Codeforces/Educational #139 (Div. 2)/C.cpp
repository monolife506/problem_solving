#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int m;
    cin >> m;

    vector<string> c(2);
    cin >> c[0] >> c[1];

    vector<vector<bool>> cache(2, vector<bool>(m, false));

    cache[0][0] = (c[0][0] == 'B');
    cache[1][0] = (c[1][0] == 'B');
    for (int i = 1; i < m; ++i)
    {
        if (c[0][i] == 'B' && c[1][i] == 'W')
        {
            cache[0][i] = cache[0][i - 1];
        }
        else if (c[0][i] == 'W' && c[1][i] == 'B')
        {
            cache[1][i] = cache[1][i - 1];
        }
        else
        {
            cache[0][i] = cache[1][i - 1];
            cache[1][i] = cache[0][i - 1];
        }
    }

    cout << (cache[0][m - 1] || cache[1][m - 1] ? "YES" : "NO") << '\n';
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