#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll x0, n;
    cin >> x0 >> n;

    if (abs(x0) % 2 == 0)
    {
        if (n % 4 == 0)
            cout << x0 << '\n';
        else if (n % 4 == 1)
            cout << x0 - n << '\n';
        else if (n % 4 == 2)
            cout << x0 + 1 << '\n';
        else
            cout << x0 + (n + 1) << '\n';
    }
    else
    {
        if (n % 4 == 0)
            cout << x0 << '\n';
        else if (n % 4 == 1)
            cout << x0 + n << '\n';
        else if (n % 4 == 2)
            cout << x0 - 1 << '\n';
        else
            cout << x0 - (n + 1) << '\n';
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

0 1 -1

p % 2 == 0
p p - 1 p + 1 p + 4 p p - 5 p + 1 p + 8 p p - 9

p % 2 != 0
p p + 1 p - 1 p - 4 p p + 5 p - 1 p - 8 p

*/