#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &ai : a)
        cin >> ai;

    int l = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[0] != a[i])
            break;

        l = i;
    }

    int r = n - 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (a[n - 1] != a[i])
            break;

        r = i;
    }

    int ans = min(n - (l + 1), n - (n - r));
    if (a[0] == a[n - 1] && l < r)
        ans = min(ans, n - ((l + 1) + (n - r)));

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