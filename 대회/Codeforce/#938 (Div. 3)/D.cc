#include <bits/stdc++.h>
// #define FILE_RW
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (auto &ai : a)
        cin >> ai;

    vector<int> b(m);
    map<int, int> cnt_b;
    for (auto &bi : b)
    {
        cin >> bi;
        cnt_b[bi]++;
    }

    map<int, int> cnt_a;

    int match_cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        cnt_a[a[i]]++;
        if (cnt_b[a[i]] > 0 && cnt_a[a[i]] <= cnt_b[a[i]])
            match_cnt++;
    }

    int ans = (match_cnt >= k);
    for (int i = m; i < n; ++i)
    {
        cnt_a[a[i - m]]--;
        if (cnt_b[a[i - m]] > 0 && cnt_a[a[i - m]] < cnt_b[a[i - m]])
            match_cnt--;

        cnt_a[a[i]]++;
        if (cnt_b[a[i]] > 0 && cnt_a[a[i]] <= cnt_b[a[i]])
            match_cnt++;

        if (match_cnt >= k)
            ans++;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

4 1 2 3

*/