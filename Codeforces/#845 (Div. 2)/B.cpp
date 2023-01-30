#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1'000'000'007;

void solve()
{
    ll n;
    cin >> n;

    ll ans = ((n - 1) * (n - 1) + (n - 1)) % MOD;
    for (ll i = 2; i <= n; ++i)
    {
        ans *= i;
        ans %= MOD;
    }

    cout << ans << '\n';
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

1 2
2 1

1 2 3 (0 -> )
1 3 2 (1 -> )
2 1 3 (1 -> )
2 3 1 (2 -> )
3 1 2 (2 -> 6)
3 2 1 (3 -> 6)

1 2 3 4 4 3 2 1 (2 + 4 + 6 = 12)

1 2 3 4 5 5 4 3 2 1 (2 + 4 + 6 + 8 = 20)

*/