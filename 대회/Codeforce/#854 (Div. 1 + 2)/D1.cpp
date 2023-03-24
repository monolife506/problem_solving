#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e14;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> cold(k + 1, 0), hot(k + 1, 0);
    for (int i = 1; i <= k; ++i)
        cin >> cold[i];
    for (int i = 1; i <= k; ++i)
        cin >> hot[i];

    vector<ll> cache(k + 1, INF), tmp(k + 1);
    cache[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        fill(tmp.begin(), tmp.end(), INF);
        for (int j = 0; j <= k; ++j)
        {
            // a[i - 1] -> a[i]
            if (a[i - 1] == a[i])
                tmp[j] = min(tmp[j], cache[j] + hot[a[i]]);
            else
                tmp[j] = min(tmp[j], cache[j] + cold[a[i]]);

            // j -> a[i]
            if (j == a[i])
                tmp[a[i - 1]] = min(tmp[a[i - 1]], cache[j] + hot[a[i]]);
            else
                tmp[a[i - 1]] = min(tmp[a[i - 1]], cache[j] + cold[a[i]]);
        }

        cache = tmp;
    }

    ll ans = INF;
    for (int i = 0; i <= k; ++i)
        ans = min(ans, cache[i]);

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