#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = a[n - 1] - a[0];
    if (n != 1)
    {
        int min_val = *min_element(a.begin(), a.end() - 1);
        int max_val = *max_element(a.begin() + 1, a.end());
        ans = max(ans, a[n - 1] - min_val);
        ans = max(ans, max_val - a[0]);

        for (int i = 0; i < n; ++i)
            ans = max(ans, a[i] - a[(i + 1) % n]);
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

5 2 2 1



*/