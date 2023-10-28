#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e15;
ll d[101], dp[101][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&dp[0][0], 101 * 1001, INF);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    ll l1, c1, k1, l2, c2, k2;
    cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;

    dp[0][0] = 0;
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 0; j <= k1; ++j)
        {
            for (ll k = 0; k <= k1 - j; ++k)
            {
                ll remain = max(0LL, d[i] - k * l1);
                ll cnt = (remain / l2) + (remain % l2 != 0);
                dp[i][j + k] = min(dp[i][j + k], dp[i - 1][j] + cnt);
            }
        }
    }

    ll ans = INF;
    for (ll i = 0; i <= k1; ++i)
    {
        if (dp[n][i] <= k2)
            ans = min(ans, i * c1 + dp[n][i] * c2);
    }

    cout << (ans != INF ? ans : -1) << '\n';
}