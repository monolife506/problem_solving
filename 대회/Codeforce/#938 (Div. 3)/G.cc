#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, m, a[101][101];
bool visited[101][101];

bool check(int num)
{
    memset(visited, false, sizeof(visited));

    visited[0][0] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] % num != 0)
                continue;

            if (i > 0 && visited[i - 1][j])
                visited[i][j] = true;
            if (j > 0 && visited[i][j - 1])
                visited[i][j] = true;
        }
    }

    return visited[n - 1][m - 1];
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    int val = a[0][0];
    int ans = 0;
    for (int i = 1; i * i <= val; ++i)
    {
        if (val % i != 0)
            continue;

        if (check(i))
            ans = max(ans, i);
        if (check(val / i))
            ans = max(ans, val / i);
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

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}