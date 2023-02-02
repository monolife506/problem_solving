#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = INT32_MIN;
    int sum = accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == -1 && a[i + 1] == -1)
            ans = max(ans, sum + 4);
        else if ((a[i] == -1 && a[i + 1] == 1) || (a[i] == 1 && a[i + 1] == -1))
            ans = max(ans, sum);
        else
            ans = max(ans, sum - 4);
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