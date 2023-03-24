#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, w, h;
    cin >> n >> w >> h;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    int l = INT32_MIN, r = INT32_MAX;
    for (int i = 0; i < n; ++i)
    {
        l = max(l, b[i] - (a[i] + w - h));
        r = min(r, b[i] - (a[i] - w + h));
    }

    cout << (l <= r ? "YES" : "NO") << '\n';
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
3 3 2
13 22 29
5 16 25

4 13 20
5 16 25

*/