#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    if (s[0] == 'a' && s[n - 1] == 'a')
    {
        cout << s[0] << " " << s.substr(1, n - 2) << " " << s[n - 1] << '\n';
    }
    else if (s[0] == 'b' && s[n - 1] == 'b')
    {
        cout << s.substr(0, n - 2) << " " << s[n - 2] << " " << s[n - 1] << '\n';
    }
    else
    {
        int idx = -1;
        for (int i = 1; i < n - 1; ++i)
        {
            if (s[i] == 'a')
            {
                idx = i;
                break;
            }
        }

        if (idx != -1)
            cout << s.substr(0, idx) << " " << s[idx] << " " << s.substr(idx + 1) << '\n';
        else
            cout << s[0] << " " << s.substr(1, n - 2) << " " << s[n - 1] << '\n';
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