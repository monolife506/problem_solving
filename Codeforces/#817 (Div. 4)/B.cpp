#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string s[2];
    cin >> s[0] >> s[1];
    for (int i = 0; i < n; ++i)
    {
        char c1 = (s[0][i] != 'B') ? s[0][i] : 'G';
        char c2 = (s[1][i] != 'B') ? s[1][i] : 'G';
        if (c1 != c2)
        {
            cout << "NO" << '\n';
            return;
        }
    }

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