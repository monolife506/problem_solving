#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c || a + c == b || b + c == a)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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