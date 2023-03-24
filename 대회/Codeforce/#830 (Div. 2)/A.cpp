#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int val = a[0];
    for (int i = 1; i < n; ++i)
        val = gcd(val, a[i]);

    if (val == 1)
    {
        cout << 0 << '\n';
        return;
    }

    b = a;
    b[n - 1] = gcd(a[n - 1], n);

    val = b[0];
    for (int i = 1; i < n; ++i)
        val = gcd(val, b[i]);

    if (val == 1)
    {
        cout << 1 << '\n';
        return;
    }

    b = a;
    b[n - 2] = gcd(a[n - 2], n - 1);

    val = b[0];
    for (int i = 1; i < n; ++i)
        val = gcd(val, b[i]);

    if (val == 1)
    {
        cout << 2 << '\n';
        return;
    }

    cout << 3 << '\n';
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

gcd(a, a - 1) = 1

*/