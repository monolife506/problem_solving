#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    reverse(t.begin(), t.end());

    string str = s + t;
    for (int i = 0; i + 1 < str.length(); ++i)
    {
        bool flag = true;
        for (int j = 0; j <= i; ++j)
        {
            if (j > 0 && str[j] == str[j - 1])
            {
                flag = false;
                break;
            }
        }
        for (int j = i + 1; j < str.length(); ++j)
        {
            if (j > i + 1 && str[j] == str[j - 1])
            {
                flag = false;
                break;
            }
        }

        if (flag)
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