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

    int y = 0, x = 0;
    for (char c : s)
    {
        if (c == 'U')
            y++;
        else if (c == 'R')
            x++;
        else if (c == 'D')
            y--;
        else // c == 'L'
            x--;

        if (y == 1 && x == 1)
        {
            cout << "YES" << '\n';
            return;
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