#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<ll> psum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int ai;
        cin >> ai;
        psum[i] = psum[i - 1] + ai;
    }

    ll ans = 1;
    for (int i = 1; i < n; ++i)
        ans = max(ans, gcd(psum[i], psum[n] - psum[i]));

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