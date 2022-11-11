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

    vector<int> l(n);
    l[0] = 0;

    ll ans = 1;
    for (int i = 1; i < n; ++i)
    {
        l[i] = max(l[i - 1], i - (a[i] - 1));
        ans += (i - l[i]) + 1;
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

0 X X X
0 1 X X
0 2 2 X
0 3 3 3

*/