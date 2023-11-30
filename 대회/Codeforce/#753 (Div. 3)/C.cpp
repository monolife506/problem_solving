#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = a[0];
    ll val = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        val += a[i] - val;
        ans = max(ans, a[i + 1] - val);
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

5
3 2 -4 -2 0

-4 -2 0 2 3

-4
-2 0 2 3

-6
0 2 3

*/