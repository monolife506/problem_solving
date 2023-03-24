#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
            ++ans;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int tmp = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
            ++tmp;
    }

    ans = min(ans, tmp);

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