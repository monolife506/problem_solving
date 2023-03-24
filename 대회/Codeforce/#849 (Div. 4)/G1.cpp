#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] += i + 1;
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (c < a[i])
            break;

        ans++;
        c -= a[i];
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