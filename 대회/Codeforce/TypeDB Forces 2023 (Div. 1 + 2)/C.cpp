#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    ll n, s;
    cin >> n >> s;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<vector<ll>> x(2, vector<ll>(n));
    for (int i = 2; i <= n - 1; ++i)
    {
        x[0][i] = min(s, max(0LL, a[i] - s));
        x[1][i] = a[i] - x[0][i];
    }

    vector<vector<ll>> cache(2, vector<ll>(n));
    cache[0][1] = a[1] * x[0][2];
    cache[1][1] = a[1] * x[1][2];
    for (int i = 2; i <= n - 2; ++i)
    {
        cache[0][i] = min(cache[0][i - 1] + (a[i] - x[0][i]) * x[0][i + 1], cache[1][i - 1] + (a[i] - x[1][i]) * x[0][i + 1]);
        cache[1][i] = min(cache[0][i - 1] + (a[i] - x[0][i]) * x[1][i + 1], cache[1][i - 1] + (a[i] - x[1][i]) * x[1][i + 1]);
    }

    cout << min(cache[0][n - 2] + (a[n - 1] - x[0][n - 1]) * a[n], cache[1][n - 2] + (a[n - 1] - x[1][n - 1]) * a[n]) << '\n';
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

1
5 5
4 3 5 6 4

16

(x - s)(a - s - x) >= 0

s <= x <= a - s
a - s <= x <= s

*/