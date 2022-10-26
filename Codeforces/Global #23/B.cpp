#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<int>> l(2, vector<int>(n, 0));
    vector<vector<int>> r(2, vector<int>(n, 0));
    for (int i = 1; i < n; ++i)
    {
        l[0][i] = l[0][i - 1] + (a[i - 1] == 0);
        l[1][i] = l[1][i - 1] + (a[i - 1] == 1);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        r[0][i] = r[0][i + 1] + (a[i + 1] == 0);
        r[1][i] = r[1][i + 1] + (a[i + 1] == 1);
    }

    int ans = INT32_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
            ans = min(ans, l[1][i] + max(0, r[0][i] - l[1][i]));
        else
            ans = min(ans, l[0][i] + r[0][i]);
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

/*

0 0 0 0 0

0 1 1 1 0

*/