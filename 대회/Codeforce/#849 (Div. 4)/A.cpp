#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    char c;
    cin >> c;

    string s = "codeforces";
    for (char c2 : s)
    {
        if (c2 == c)
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