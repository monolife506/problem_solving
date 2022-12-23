#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    int num = 1;
    int ten = 1;
    int ans = 0;
    while (num * ten <= n)
    {
        ans++;
        if (num < 9)
        {
            num++;
        }
        else
        {
            ten *= 10;
            num = 1;
        }
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