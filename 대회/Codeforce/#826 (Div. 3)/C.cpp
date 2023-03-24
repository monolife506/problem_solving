#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), psum(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    int ans = n;
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        int len = 0;
        int t = i;

        for (int j = i + 1; j <= n; ++j)
        {
            sum += a[j];
            ++len;

            if (sum > psum[i])
                break;

            if (sum == psum[i])
            {
                t = max(t, len);
                sum = 0;
                len = 0;

                if (j == n)
                    ans = min(ans, t);
            }
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