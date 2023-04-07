#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<vector<string>> a(n);
    for (int i = 0; i < n * 2 - 2; ++i)
    {
        string s;
        cin >> s;
        a[s.length()].push_back(s);
    }

    if (n % 2 == 0)
    {
        reverse(a[n / 2][1].begin(), a[n / 2][1].end());
        cout << (a[n / 2][0] == a[n / 2][1] ? "YES" : "NO") << '\n';
    }
    else
    {
        reverse(a[n / 2 + 1][1].begin(), a[n / 2 + 1][1].end());
        cout << (a[n / 2 + 1][0] == a[n / 2 + 1][1] ? "YES" : "NO") << '\n';
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

/*

abcba

abc
cba

*/