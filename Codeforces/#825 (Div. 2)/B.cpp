#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n), b(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    b[0] = a[0];
    for (int i = 1; i <= n; ++i)
    {
        b[i] = a[i - 1];
        if (i != n && b[i] % a[i] != 0)
            b[i] *= a[i] / gcd(b[i], a[i]);

        if (gcd(b[i - 1], b[i]) != a[i - 1])
        {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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

b % a != 0



7 * 4 = 28
3 * 2 = 6

28, 6 = 2

*/