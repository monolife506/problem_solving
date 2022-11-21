#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<ll> psum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    map<ll, int> cnt;
    int ans = 0, max_cnt = 0;
    bool zero_flag = false;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            ans += (zero_flag) ? max_cnt : cnt[0];
            zero_flag = true;
            max_cnt = 0;
            cnt.clear();
        }

        max_cnt = max(max_cnt, ++cnt[psum[i]]);
    }

    ans += (zero_flag) ? max_cnt : cnt[0];

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

1 1 1 2 1 1 2 2 1

1
1
1
2 1
2

*/