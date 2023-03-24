#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = 0;

    priority_queue<ll> max_pq;
    ll cur = 0;
    for (int i = m - 1; i > 0; --i)
    {
        cur += a[i];
        max_pq.push(a[i]);
        while (cur > 0)
        {
            cur -= 2 * max_pq.top();
            max_pq.pop();
            ans++;
        }
    }

    priority_queue<ll, vector<ll>, greater<ll>> min_pq;
    cur = 0;
    for (int i = m; i < n; ++i)
    {
        cur += a[i];
        min_pq.push(a[i]);
        while (cur < 0)
        {
            cur -= 2 * min_pq.top();
            min_pq.pop();
            ans++;
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

1
4 1
10 -7 -5 -4

10 -7 -5 -3
10 3 -2 -5

10 7 -5 -3
10 17 12 9

10 7 5 -3
10 17
*/