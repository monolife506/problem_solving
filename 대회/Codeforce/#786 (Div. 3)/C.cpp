#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    string s, t;
    cin >> s >> t;

    bool flag[2][26] = {};
    for (int i = 0; i < t.length(); ++i)
        flag[1][t[i] - 'a'] = true;

    if (!flag[1][0])
        cout << (1LL << s.length()) << '\n';
    else
    {
        if (t.length() > 1)
            cout << -1 << '\n';
        else
            cout << 1 << '\n';
    }
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