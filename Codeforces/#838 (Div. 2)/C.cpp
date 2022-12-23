#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll two[200001];

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll num = 0;
    ll ans = 1;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
            num++;
        else
            num = 0;

        ans += two[num];
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    two[0] = 1;
    for (int i = 1; i <= 200000; ++i)
        two[i] = (two[i - 1] * 2) % MOD;

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

101101111

1
1x0 -> 100: 1
1x0x1 -> 10011: 1
1x0x1x1 -> 10011x1: 2
1x0x1x1x0 -> 100110100: 1
1x0x1x1x0x0 -> 100110100x0

x1 -> 01, 11
x0 -> 00, 01

*/