#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<pii> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].first >> p[i].second;

    vector<int> f(51, 0);
    for (int i = 0; i < n; ++i)
    {
        if (p[i].first <= k && k <= p[i].second)
        {
            for (int j = p[i].first; j <= p[i].second; ++j)
                f[j]++;
        }
    }
    for (int i = 1; i <= 50; ++i)
    {
        if (i == k)
            continue;

        if (f[i] >= f[k])
        {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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