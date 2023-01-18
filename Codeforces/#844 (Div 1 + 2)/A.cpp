#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int w, d, h, a, b, f, g;
    cin >> w >> d >> h >> a >> b >> f >> g;

    int ans1 = h + abs(a - f) + min(b + g, (d - b) + (d - g));
    int ans2 = h + abs(b - g) + min(a + f, (w - a) + (w - f));
    cout << min(ans1, ans2) << '\n';
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