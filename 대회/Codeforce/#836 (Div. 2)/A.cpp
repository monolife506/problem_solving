#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    cout << s;
    reverse(s.begin(), s.end());
    cout << s << '\n';
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