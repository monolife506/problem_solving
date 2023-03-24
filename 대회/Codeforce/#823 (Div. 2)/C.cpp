#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    string ans;

    int r = -1;
    for (int i = 0; i <= 9; ++i)
    {
        int idx = -1;
        for (int j = r + 1; j < s.length(); ++j)
        {
            if (s[j] == '0' + i)
                idx = j;
        }

        if (idx != -1)
        {
            for (int j = r + 1; j <= idx; ++j)
            {
                if (s[j] == '0' + i)
                    ans.push_back('0' + i);
                else
                    ans.push_back(min('9', (char)(s[j] + 1)));
            }

            r = idx;
        }
    }

    sort(ans.begin(), ans.end());

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