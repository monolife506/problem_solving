#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, H, M;
    cin >> n >> H >> M;

    int cur = H * 60 + M;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
    {
        int t = v[i].first * 60 + v[i].second;
        if (cur <= t)
        {
            cout << (t - cur) / 60 << " " << (t - cur) % 60 << '\n';
            return;
        }
    }

    int t = v[0].first * 60 + v[0].second;
    cout << ((1440 - cur) + t) / 60 << " " << ((1440 - cur) + t) % 60 << '\n';
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