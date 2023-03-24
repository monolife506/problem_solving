#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), cnt(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        cnt[i] = (a[i] == 1) ? cnt[i - 1] : cnt[i - 1] + 1;
    }

    for (int i = 1; i < n; ++i)
    {
        if (cnt[i] == cnt[n] - cnt[i])
        {
            cout << i << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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