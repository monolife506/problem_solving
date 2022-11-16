#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    bool flag[2] = {true, true};
    for (int i = 0; i < n; ++i)
    {
        int ai = a[i] - '0';
        int bi = b[i] - '0';

        if (ai != bi)
            flag[0] = false;
        if (ai != 1 - bi)
            flag[1] = false;
    }

    if (!flag[0] && !flag[1])
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';

        int flip_cnt;
        if (flag[0])
            flip_cnt = 0;
        else
            flip_cnt = 1;

        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == '1')
            {
                ans.push_back({i + 1, i + 1});
                ++flip_cnt;
            }
        }

        if (flip_cnt % 2 == 1)
        {
            ans.push_back({1, n});
            ans.push_back({1, 1});
            ans.push_back({2, n});
        }

        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i].first << " " << ans[i].second << '\n';
    }
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

1111
1111

0111
1000

*/