#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int a = (ans % 2 == 0) ? (s[i] - '0') : !(s[i] - '0');
        int b = (ans % 2 == 0) ? (s[i + 1] - '0') : !(s[i + 1] - '0');

        if (a > b)
            ++ans;
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

101

110

*/