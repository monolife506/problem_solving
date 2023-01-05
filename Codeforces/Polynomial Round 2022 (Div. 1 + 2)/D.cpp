#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<pii> cnt(n, {0, 0});
    int total_cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cnt[i].second = i;
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            total_cnt += a[i][j];
            cnt[i].first += a[i][j];
        }
    }

    if (total_cnt % n != 0)
    {
        cout << -1 << '\n';
        return;
    }

    sort(cnt.begin(), cnt.end());

    int l = 0, r = n - 1;

    vector<tuple<int, int, int>> ans;
    while (l <= r)
    {
        for (int i = 0; i < m && cnt[l].first != total_cnt / n && cnt[r].first != total_cnt / n; ++i)
        {
            if (a[cnt[l].second][i] == 0 && a[cnt[r].second][i] == 1)
            {
                ans.push_back({cnt[l].second + 1, cnt[r].second + 1, i + 1});
                a[cnt[l].second][i] = 1;
                a[cnt[r].second][i] = 0;
                cnt[l].first++;
                cnt[r].first--;
            }
        }

        if (cnt[l].first == total_cnt / n)
            l++;
        if (cnt[r].first == total_cnt / n)
            r--;
    }

    cout << ans.size() << '\n';
    for (auto t : ans)
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';
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