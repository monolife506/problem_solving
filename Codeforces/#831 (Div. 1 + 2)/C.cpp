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

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    n = a.size();
    if (n == 1)
    {
        cout << 0 << '\n';
    }
    else if (n == 2)
    {
        cout << (a[n - 1] - a[0]) * 2 << '\n';
    }
    else
    {
        int ans = 0;
        for (int i = 2; i < n; ++i)
            ans = max(ans, (a[i] - a[0]) + (a[i] - a[i - 1]));
        for (int i = n - 3; i >= 0; --i)
            ans = max(ans, (a[n - 1] - a[i]) + (a[i + 1] - a[i]));

        cout << ans << '\n';
    }
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

2
14
5 5 4 2 2 2 4 5 5 3 5 5 5 1
14
1 1 1 5 1 1 1 4 5 5 5 1 1 1

1 4 5

5
7


1 2 9 10

1
9 10
2

1 4 5
7

1 2 5
7

*/