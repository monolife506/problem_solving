#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    a[0] = 1073741824;
    a[1] = 1073741825;
    a[2] = 1;
    for (int i = 3; i < n; ++i)
    {
        a[i] = (i - 2) * 2;
        a[1] ^= a[i];
    }

    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";

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

/*

1
0 1
0 2 3
0 1 2 3


*/