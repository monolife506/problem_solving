#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];

    if (m == 1)
    {
        cout << (k == 1 ? "YES" : "NO") << '\n';
    }
    else
    {
        sort(a.begin(), a.end());

        ll total = 0;
        for (int i = 0; i < m - 1; ++i)
            total += min(a[m - 1] - 1, a[i]);

        cout << (1LL * (a[m - 1] - 1) * (k - 1) <= total ? "YES" : "NO") << '\n';
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



k = 3
O ?? O ?? O ??

3 1


*/