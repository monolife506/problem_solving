#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    if (a[0] == a[n - 1])
    {
        cout << n / 2 << '\n';
    }
    else
    {
        ll ans = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] != a[i - 1])
                ans = max(ans, 1LL * i * (n - i));
        }

        cout << ans << '\n';
    }
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

1 2 2 3 5 5

1 2 2 3 3 4 4 4 6 7 7 9

a[i] < a[j]: all
a[i] == a[j]: 1
a[i] > a[j]: all

*/