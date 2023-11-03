#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 9;
ll dp[1000001];

ll f(int cur)
{
    if (cur == 1)
        return 1;
    if (cur == 2)
        return 2;
    if (cur == 3)
        return 4;
    if (dp[cur] != -1)
        return dp[cur];

    return dp[cur] = (f(cur - 1) + f(cur - 2) + f(cur - 3)) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dp, -1, sizeof(dp));

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        int n;
        cin >> n;

        cout << f(n) << '\n';
    }
}