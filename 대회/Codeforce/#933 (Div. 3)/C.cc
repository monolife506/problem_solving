#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    vector<bool> flag(n, true);
    for (int i = 0; i < n - 4; ++i)
    {
        string substr = s.substr(i, 5);
        if (substr == "mapie")
        {
            ans++;
            flag[i + 2] = false;
        }
    }

    string new_s;
    for (int i = 0; i < n; ++i)
    {
        if (flag[i])
            new_s.push_back(s[i]);
    }

    int m = new_s.length();
    for (int i = 0; i < m - 2; ++i)
    {
        string substr = new_s.substr(i, 3);
        if (substr == "map")
            ans++;
        if (substr == "pie")
            ans++;
    }

    cout << ans << '\n';
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

/*

mapie

*/