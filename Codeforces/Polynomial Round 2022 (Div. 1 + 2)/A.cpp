#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string a;
    cin >> a;

    int cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == '0')
            cout << '+';
        else
            cout << (++cnt % 2 == 1 ? '-' : '+');
    }

    cout << '\n';
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