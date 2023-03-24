#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    ll w = 0, h = 0;
    for (int i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        w += a;
        h = max(h, b);
    }

    cout << (w + h) * 2 << '\n';
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

2 * ((a1 + a2 + ... + an) + max(b1, b2, ..., bn))
3 +

*/