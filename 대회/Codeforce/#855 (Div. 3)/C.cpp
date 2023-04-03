#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    ll ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i)
    {
        int si;
        cin >> si;
        if (si == 0)
        {
            if (!pq.empty())
            {
                ans += pq.top();
                pq.pop();
            }
        }
        else
        {
            pq.push(si);
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