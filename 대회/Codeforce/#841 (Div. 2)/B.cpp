#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1'000'000'007;

void solve()
{
    ll n;
    cin >> n;

    ll ans = (n % 3 == 0) ? n / 3 : n;
    ans *= (n % 3 == 2) ? (n + 1) / 3 : (n + 1);
    ans %= MOD;
    ans *= (n % 3 == 1) ? (n * 2 + 1) / 3 : (n * 2 + 1);
    ans %= MOD;
    ans += MOD - (((n * (n + 1)) / 2) % MOD);
    ans %= MOD;

    cout << (ans * 2022) % MOD << '\n';
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

1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20
5 10 15 20 25

sum(k^2 * 2 - k) (1 <= k <= n)

*/