#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, c;
    cin >> n >> c;

    vector<int> cnt(101, 0);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100; ++i)
        ans += (cnt[i] > c) ? c : cnt[i];

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