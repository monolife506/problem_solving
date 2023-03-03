#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    string a, b;
    cin >> a >> b;

    if (a.front() == b.front())
    {
        cout << "YES" << '\n'
             << a.front() << "*" << '\n';

        return;
    }
    else if (a.back() == b.back())
    {
        cout << "YES" << '\n'
             << "*" << a.back() << '\n';

        return;
    }
    else if (a.length() >= 2 && b.length() >= 2)
    {
        for (int i = 0; i + 1 < a.length(); ++i)
        {
            for (int j = 0; j + 1 < b.length(); ++j)
            {
                if (a.substr(i, 2) == b.substr(j, 2))
                {
                    cout << "YES" << '\n'
                         << "*" << a.substr(i, 2) << "*" << '\n';

                    return;
                }
            }
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