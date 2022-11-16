#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll cnt[2] = {};
    ll tmp = 0, ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        ++cnt[s[i] - '0'];
        ++tmp;

        if (i == s.length() - 1 || s[i] != s[i + 1])
        {
            ans = max(ans, tmp * tmp);
            tmp = 0;
        }
    }

    ans = max(ans, cnt[0] * cnt[1]);
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