#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void solve()
{
    int n, m;
    cin >> n;

    string s;
    cin >> s;

    bool leading_zero = true;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            leading_zero = false;
            s = s.substr(i);
            break;
        }
    }

    n = s.length();
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            m = n - i;
            break;
        }
    }

    string s1(m, 0), s2(m, 0), s3(m, 0);
    for (int i = 0; i < m; ++i)
        s1[i] = s[(n - m) + i];

    for (int i = 0; i + m - 1 < n; ++i)
    {
        string tmp(m, 0);
        for (int j = 0; j < m; ++j)
            s2[j] = s[i + j];
        for (int j = 0; j < m; ++j)
            tmp[j] = (char)(((s1[j] == '1') || (s2[j] == '1')) + '0');

        if (tmp > s3)
            s3 = tmp;
    }

    string ans = s.substr(0, n - m) + s3;

    leading_zero = true;
    for (int i = 0; i < n; ++i)
    {
        if (ans[i] == '1')
            leading_zero = false;
        if (!leading_zero)
            cout << ans[i];
    }

    if (leading_zero)
        cout << 0;

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

/*

011101111101111111101110110

*/