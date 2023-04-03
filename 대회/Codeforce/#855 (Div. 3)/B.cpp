#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt[2][26] = {};
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
            cnt[0][c - 'a']++;
        else // c >= 'A' && c <= 'Z'
            cnt[1][c - 'A']++;
    }

    int ans = 0, tmp = 0;
    for (int i = 0; i < 26; ++i)
    {
        ans += min(cnt[0][i], cnt[1][i]);
        tmp += (cnt[0][i] + cnt[1][i]) / 2 - min(cnt[0][i], cnt[1][i]);
    }
    ans += min(tmp, k);
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