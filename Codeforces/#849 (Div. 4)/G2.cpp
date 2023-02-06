#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, c;
    cin >> n >> c;

    vector<int> a(n + 1, 0), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        l[i] = a[i] + i;
        r[i] = a[i] + n + 1 - i;
        a[i] = min(l[i], r[i]);
    }

    sort(a.begin(), a.end());

    vector<ll> psum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        psum[i] = psum[i - 1] + a[i];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c < l[i])
            continue;

        int cur = c - l[i];
        int cnt = upper_bound(psum.begin(), psum.end(), cur) - psum.begin();
        int idx = upper_bound(a.begin(), a.end(), min(l[i], r[i])) - a.begin();

        if (cnt >= idx)
        {
            cnt--;
            if (psum[cnt + 1] - min(l[i], r[i]) <= cur)
                cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << min(ans, n) << '\n';
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

l 1
나머지 그리디

1
4 10
1 1 4 4

l: 2 3 7 8
r: 5 4 6 5
a: 0 2 3 5 6
p: 0 2 5 10 16

8 7 3 2

1
4 26
1 3 4 3


1
5 600000000
500000000 400000000 300000000 200000000 100000000

*/