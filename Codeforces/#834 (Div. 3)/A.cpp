#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    string t;
    for (int i = 0; i < 100; ++i)
    {
        if (i % 3 == 0)
            t.push_back('Y');
        else if (i % 3 == 1)
            t.push_back('e');
        else // (i % 3 == 2)
            t.push_back('s');
    }

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < s.length(); ++j)
        {
            if (i + j >= t.length())
                break;
            if (s[j] != t[i + j])
                break;

            if (j == s.length() - 1)
            {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
    return;
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