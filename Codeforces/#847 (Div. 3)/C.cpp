#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> s(n, vector<int>(n - 1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
            cin >> s[i][j];
    }

    vector<int> p(n);
    for (int i = 1; i <= n; ++i)
    {
        int l_max = 0, r_max = 0;
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n - 1; ++k)
            {
                if (s[j][k] == i)
                {
                    l_max = max(l_max, k);
                    r_max = max(r_max, (n - 2) - k);
                }
            }
        }

        if (l_max == 0)
            p[0] = i;
        else if (r_max == 0)
            p[n - 1] = i;
        else
            p[l_max] = i;
    }

    for (int i = 0; i < n; ++i)
        cout << p[i] << " ";

    cout << "\n";
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