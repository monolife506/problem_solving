#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int a, b;
    cin >> a >> b;

    a = abs(a);
    b = abs(b);

    int val = min(a, b);
    int ans = val * 2;

    a -= val;
    b -= val;

    if (max(a, b) >= 1)
        ans++;
    if (max(a, b) >= 2)
        ans += (max(a, b) - 1) * 2;

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