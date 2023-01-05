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

    int l = 0, r = 1000000000;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i - 1])
        {
            r = min(r, (a[i] + a[i - 1]) / 2);
        }
        else if (a[i] < a[i - 1])
        {
            if ((a[i] + a[i - 1]) % 2 == 0)
                l = max(l, (a[i] + a[i - 1]) / 2);
            else
                l = max(l, (a[i] + a[i - 1]) / 2 + 1);
        }

        if (l > r)
        {
            cout << -1 << '\n';
            return;
        }
    }

    cout << l << '\n';
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

15 20
0 ~ 17

10 1
6 ~ INF

5

*/