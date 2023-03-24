#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> l(n), r(n);

    vector<bool> flag(26, false);
    l[0] = 1;
    flag[s[0] - 'a'] = true;
    for (int i = 1; i < n - 1; ++i)
    {
        l[i] = l[i - 1];
        if (!flag[s[i] - 'a'])
        {
            flag[s[i] - 'a'] = true;
            l[i]++;
        }
    }

    for (int i = 0; i < 26; ++i)
        flag[i] = false;

    r[n - 1] = 1;
    flag[s[n - 1] - 'a'] = true;
    for (int i = n - 2; i > 0; --i)
    {
        r[i] = r[i + 1];
        if (!flag[s[i] - 'a'])
        {
            flag[s[i] - 'a'] = true;
            r[i]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
        ans = max(ans, l[i] + r[i + 1]);

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