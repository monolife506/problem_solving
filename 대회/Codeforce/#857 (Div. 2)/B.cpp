#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    int cnt[2] = {};
    for (int i = 0; i < n; ++i)
    {
        int bi;
        cin >> bi;

        if (bi == 1)
        {
            cnt[0]++;
        }
        else
        {
            cnt[1] += cnt[0];
            cnt[0] = 0;
        }

        if (cnt[1] == 0)
            ans = max(ans, cnt[0]);
        else
            ans = max(ans, cnt[0] + (cnt[1] / 2 + 1));
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

0
0

2
1 1 -> 2

4
3 1 -> 3
2 2 -> 2

6
5 1 -> 4
4 2 -> 3
3 3 ->

8
7 1 -> 5
5 3 -> 5

*/