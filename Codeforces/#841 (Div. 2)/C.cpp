#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<ll> xor_cnt(n * 2 + 1, 0);
    xor_cnt[0] = 1;

    int cur_xor = 0;
    ll odd_cnt = 0;

    for (ll i = 0; i < n; ++i)
    {
        cur_xor ^= a[i];
        for (ll j = 0; j * j < n * 2; ++j)
        {
            if ((cur_xor ^ (j * j)) < 2 * n)
                odd_cnt += xor_cnt[cur_xor ^ (j * j)];
        }

        xor_cnt[cur_xor]++;
    }

    cout << (n * (n + 1) / 2) - odd_cnt << '\n';
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

0 <= xor <= 2^18 - 1

*/