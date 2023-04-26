#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, k, d, w;
    cin >> n >> k >> d >> w;

    vector<int> tp(n), t;
    for (int i = 0; i < n; ++i)
    {
        cin >> tp[i];
        t.push_back(tp[i]);
        t.push_back(tp[i] + w);
    }

    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    int ans = 0, l = 0, r = 0, cnt = 0, x = 0;
    for (int cur : t)
    {
        if (cnt != 0 && cur > x + d)
            cnt = 0;

        while (r < n && cur == tp[r])
        {
            r++;
            if (cnt != 0)
            {
                l++;
                cnt--;
            }
        }

        while (l != r && cur == tp[l] + w)
        {
            if (cnt == 0)
            {
                cnt = k;
                x = cur;
                ans++;
            }

            l++;
            cnt--;
        }

        while (l != r && cnt != 0)
        {
            l++;
            cnt--;
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

1 2 3 10 11 18

4 -> 1 2 3
13 -> 10 11
18 -> 18

3 3 3 3 3 4

3 -> 3 3 3 3
3 -> 3 3
4 -> 4

0 1 2 3 4 5 6 7 8

2 -> 0 1 2
3 -> 3
4 -> 4

7 -> 5 6 7
8 -> 8

*/