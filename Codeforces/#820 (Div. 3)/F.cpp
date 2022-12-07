#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 987654321;

void solve()
{
    string s;
    cin >> s;

    int w, m;
    cin >> w >> m;

    vector<int> psum(s.length() + 1, 0);
    for (int i = 1; i <= s.length(); ++i)
        psum[i] = psum[i - 1] + (s[i - 1] - '0');

    vector<vector<int>> l_min(9, vector<int>(2, INF));
    for (int i = 1; i + w - 1 <= s.length(); ++i)
    {
        int v = (psum[i + w - 1] - psum[i - 1]) % 9;
        if (i < l_min[v][0])
        {
            l_min[v][1] = l_min[v][0];
            l_min[v][0] = i;
        }
        else if (i < l_min[v][1])
        {
            l_min[v][1] = i;
        }
    }

    for (int q = 0; q < m; ++q)
    {
        int l, r, k;
        cin >> l >> r >> k;

        int v = (psum[r] - psum[l - 1]) % 9;
        pii ans = {INF, INF};
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if ((i * v + j) % 9 != k)
                    continue;

                if (i == j)
                {
                    if (l_min[i][1] == INF)
                        continue;

                    ans = min(ans, pii(l_min[i][0], l_min[i][1]));
                }
                else
                {
                    if (l_min[i][0] == INF || l_min[j][0] == INF)
                        continue;

                    ans = min(ans, pii(l_min[i][0], l_min[j][0]));
                }
            }
        }

        if (ans == pii(INF, INF))
            cout << -1 << " " << -1 << '\n';
        else
            cout << ans.first << " " << ans.second << '\n';
    }
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

/*

v(l, r) % 9 = (v[l] + v[l + 1] + ... + v[r]) % 9


*/