#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[0] == 1)
            ans += a[i] - 1;
        else if (a[i] % (a[0] * 2 - 1) == 0)
            ans += a[i] / (a[0] * 2 - 1) - 1;
        else
            ans += a[i] / (a[0] * 2 - 1);
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

a[0]

k * a[0] <= x <= k * (2 * a[0] - 2)

600 ~ 1199 1
1200 ~ 2398 2
2399 ~

1
3
600 3597 3598



*/