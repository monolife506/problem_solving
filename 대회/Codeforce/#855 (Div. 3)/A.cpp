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

    const char cl[] = {'m', 'e', 'o', 'w'};
    const char ch[] = {'M', 'E', 'O', 'W'};

    if (s[0] != 'm' && s[0] != 'M')
    {
        cout << "NO" << '\n';
        return;
    }
    if (s[n - 1] != 'w' && s[n - 1] != 'W')
    {
        cout << "NO" << '\n';
        return;
    }

    int i = 0;
    for (char c : s)
    {
        if (c == cl[i] || c == ch[i])
            continue;

        if (i == 3)
        {
            cout << "NO" << '\n';
            return;
        }

        if (c == cl[i + 1] || c == ch[i + 1])
        {
            i++;
            continue;
        }

        cout << "NO" << '\n';
        return;
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