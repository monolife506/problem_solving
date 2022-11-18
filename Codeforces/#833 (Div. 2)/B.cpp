#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        vector<int> cnt(10, 0);
        int d = 0, max_cnt = 0;
        for (int j = 0; j < 100 && i + j < n; ++j)
        {
            if (cnt[s[i + j] - '0'] == 0)
                ++d;

            ++cnt[s[i + j] - '0'];
            max_cnt = max(max_cnt, cnt[s[i + j] - '0']);

            if (d >= max_cnt)
                ++ans;
        }
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

9 *9

*/