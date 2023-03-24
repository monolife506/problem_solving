#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> idx(1001, -1);
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        idx[a] = max(idx[a], i);
    }

    int ans = -1;
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= 1000; ++j)
        {
            if (idx[i] == -1 || idx[j] == -1)
                continue;
            if (gcd(i, j) == 1)
                ans = max(ans, idx[i] + idx[j]);
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