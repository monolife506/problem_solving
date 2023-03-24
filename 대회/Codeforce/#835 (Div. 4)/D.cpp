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

    int l = 0, r = 0, cnt = 0;
    while (r <= n - 1)
    {
        if ((l == 0 || a[l - 1] > a[l]) && (r == n - 1 || a[r] < a[r + 1]))
            ++cnt;

        if (r < n - 1 && a[l] == a[r + 1])
        {
            ++r;
        }
        else
        {
            l = r + 1;
            r = l;
        }
    }

    cout << (cnt == 1 ? "YES" : "NO") << '\n';
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