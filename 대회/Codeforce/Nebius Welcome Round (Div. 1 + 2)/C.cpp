#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    ll n, x, p;
    cin >> n >> x >> p;
    for (ll f = 1; f <= min(n * 2, p); ++f)
    {
        ll num = f * (f + 1) / 2;
        if (num % n == (n - x) % n)
        {
            cout << "Yes" << '\n';
            return;
        }
    }

    cout << "No" << '\n';
    return;
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



*/