#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << n / 2 << '\n';
        for (int i = 0; i < n / 2; ++i)
            cout << 2 + (i * 3) << " " << (n * 3) - (i * 3) << '\n';
    }
    else
    {
        cout << n / 2 + 1 << '\n';
        for (int i = 0; i < n / 2 + 1; ++i)
            cout << 2 + (i * 3) << " " << (n * 3) - (i * 3) << '\n';
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

BNA

BANBAN

BNNBAA

BNNBNABAA

*/