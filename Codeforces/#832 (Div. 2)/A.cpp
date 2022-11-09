#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    ll sum[2] = {0, 0};
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;

        if (ai > 0)
            sum[0] += ai;
        else
            sum[1] += -ai;
    }

    cout << abs(sum[0] - sum[1]) << '\n';
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