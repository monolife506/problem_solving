#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int q;
    cin >> q;

    vector<ll> s(26, 0), t(26, 0);
    s[0] = t[0] = 1;
    for (int i = 0; i < q; ++i)
    {
        int d, k;
        cin >> d >> k;

        string x;
        cin >> x;

        for (char c : x)
        {
            if (d == 1)
                s[c - 'a'] += k;
            else
                t[c - 'a'] += k;
        }

        string tmp1, tmp2;
        for (int j = 0; j < 26; ++j)
        {
            if (s[j] != 0)
                tmp1.push_back('a' + j);
        }
        for (int j = 25; j >= 0; --j)
        {
            if (t[j] != 0)
                tmp2.push_back('a' + j);
        }

        if (tmp1 < tmp2)
        {
            cout << "YES" << '\n';
        }
        else if (tmp1 == tmp2)
        {
            cout << (s[tmp1[0] - 'a'] < t[tmp2[0] - 'a'] ? "YES" : "NO") << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
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