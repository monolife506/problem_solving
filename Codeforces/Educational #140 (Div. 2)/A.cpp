#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if ((x1 == x2 && y2 == y3) || (x1 == x3 && y3 == y2) || (x2 == x1 && y1 == y3) || (x2 == x3 && y3 == y1) ||
        (x3 == x1 && y1 == y2) || (x3 == x2 && y2 == y1))
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
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