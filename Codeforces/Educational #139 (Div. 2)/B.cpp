#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n >= 4)
    {
        set<string> str;
        str.insert(s.substr(0, 2));
        string pre = s.substr(1, 2);
        for (int i = 2; i < n - 1; ++i)
        {
            string cur = s.substr(i, 2);
            if (str.find(cur) != str.end())
            {
                cout << "YES" << '\n';
                return;
            }

            str.insert(pre);
            pre = cur;
        }
    }

    cout << "NO" << '\n';
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