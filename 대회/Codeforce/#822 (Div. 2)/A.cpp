#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = INT64_MAX;
    for (int i = 0; i + 2 < n; ++i)
    {
        ans = min(ans, (a[i + 1] - a[i]) + (a[i + 2] - a[i]));
        ans = min(ans, (a[i + 1] - a[i]) + (a[i + 2] - a[i + 1]));
        ans = min(ans, (a[i + 2] - a[i]) + (a[i + 2] - a[i + 1]));
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