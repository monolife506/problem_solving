#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    map<pii, int> mod;
    for (auto &ai : a)
    {
        cin >> ai;
        mod[{ai % x, ai % y}]++;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += mod[{(x - (a[i] % x)) % x, a[i] % y}];
        if (a[i] % x == (x - (a[i] % x)) % x)
            ans--;
    }

    cout << ans / 2 << '\n';
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

a + b === x
x - a === b

a - b === y
a - y === b


5

14
9
4
-4

*/