#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    string kb;
    cin >> kb;

    int idx[26] = {};
    for (int i = 0; i < 26; ++i)
        idx[kb[i] - 'a'] = i;

    string s;
    cin >> s;

    ll ans = 0;
    for (int i = 1; i < s.length(); ++i)
        ans += abs(idx[s[i - 1] - 'a'] - idx[s[i] - 'a']);

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