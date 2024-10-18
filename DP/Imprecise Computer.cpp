#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int d[1000001];
bool dp[2][1000001];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    if (d[1] == 0)
    {
        dp[0][1] = true;
    }
    else if (d[1] == 1)
    {
        dp[1][1] = true;
    }
    else // d[1] >= 2
    {
        cout << "NO" << endl;
        return;
    }

    for (int i = 2; i < n; ++i)
    {
        if (d[i] == 0)
        {
            if (dp[0][i - 1])
                dp[0][i] = true;
            if (dp[1][i - 1])
                dp[1][i] = true;
        }
        else if (d[i] == 1)
        {
            if (dp[0][i - 1])
                dp[1][i] = true;
            if (dp[1][i - 1])
                dp[0][i] = true;
        }
        else if (d[i] == 2 && dp[1][i - 1])
        {
            dp[1][i] = true;
        }
        else // d[i] >= 3
        {
            cout << "NO" << endl;
            return;
        }
    }

    if ((d[n] == 0 && dp[0][n - 1]) || (d[n] == 1 && dp[1][n - 1]))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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

0 0 1 1
1 0 1 0

*/